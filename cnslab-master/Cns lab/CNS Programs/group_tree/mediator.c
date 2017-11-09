#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <signal.h>
#include <sys/ipc.h>
#include <netdb.h>
#include <stdlib.h>
#include <strings.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define MAXHOSTNAME 256
struct table
{
	int nsfd;
	int group;
	int level;
};
struct table t[100];
int count=0;
struct sockaddr_in socketInfo;
struct hostent *hPtr;
int sfd;
int portNumber = 8081;
int shmid,*pid,shid;
int max(struct table t[],int size)
{
	int i,m=t[0].nsfd;
	for(i=1;i<size;i++)
	if(t[i].nsfd>m)
	m=t[i].nsfd;
	return m;
}

int main()
{
   if((sfd=socket(AF_INET,SOCK_STREAM,0))<0)
   {
      close(sfd);
      perror("socket...");
      exit(EXIT_FAILURE);
   }
   socketInfo.sin_family=AF_INET;
   socketInfo.sin_addr.s_addr = inet_addr("127.0.0.1");
   socketInfo.sin_port = htons(portNumber);
   if(bind(sfd,(struct sockaddr *)&socketInfo,sizeof(socketInfo))<0)
   {
      close(sfd);
      exit(EXIT_FAILURE);
   }
   listen(sfd,1);
  
   fd_set rfds;
   struct timeval tv;
   int ret,i,j;
   tv.tv_sec=1;
   tv.tv_usec=0;

   printf("CONNECTED\n");
   while(1)
   {
	//printf("%d\n",count);
	FD_ZERO(&rfds);
	int m=max(t,count);
	m=m>sfd?m:sfd;
	m+=1;
	FD_SET(sfd,&rfds);
	for(i=0;i<count;i++)
	FD_SET(t[i].nsfd,&rfds);
	ret=select(m,&rfds,NULL,NULL,&tv);
	if(ret>0)
	printf("%d\n",ret);
	if(ret>0)
	{
		if(FD_ISSET(sfd,&rfds))
		{
			t[count].nsfd=accept(sfd,NULL,NULL);
			int rc=0;
   			char buf[512];
   			rc=recv(t[count].nsfd,buf,512,0);
   			buf[rc]='\0';
   			printf("Received: %s\n",buf);
   			int sgroup=10*(buf[0]-'0')+(buf[1]-'0');
   			int slevel=10*(buf[2]-'0')+(buf[3]-'0');
   			t[count].group=sgroup;
   			t[count].level=slevel;
   			count++;
   		}
		else
		for(i=0;i<count;i++)
		{
			if(FD_ISSET(t[i].nsfd,&rfds))
			{
				int rc=0;
   				char buf[512];
   				rc=recv(t[i].nsfd,buf,512,0);
   				buf[rc]='\0';
   				printf("Number of bytes read: %d\n",rc);
   				printf("Received: %s\n",buf);

   				int dgroup=10*(buf[0]-'0')+(buf[1]-'0');
   				int dlevel=10*(buf[2]-'0')+(buf[3]-'0');

   				for(j=0;j<count;j++)
   				{
   					if((t[j].group==dgroup)&&(t[j].level==dlevel))
   					{
   						send(t[j].nsfd,buf,strlen(buf),0);
   						break;
   					}
   				}
			}
		}
	}
   }
   return 0;
}

