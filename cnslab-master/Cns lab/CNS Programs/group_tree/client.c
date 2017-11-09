#include <sys/types.h>
#include <sys/socket.h>
#include <signal.h>
#include <netdb.h>
#include <stdlib.h>
#include <strings.h>
#include <stdio.h>
#include <pthread.h>
#include <string.h>
#define MAXHOSTNAME 256
#define SIZE 256
int sgroup,slevel,dgroup,dlevel;
unsigned char S[SIZE];
int i,j;
char key[]="123456789";
void generateKey(unsigned char Key[])
{
    unsigned char tmp;
    for(i=0;i<SIZE;i++)
        S[i]=i;
    j=0;
    for(i=0;i<SIZE;i++)
    {
        j=(j+S[i]+Key[i%strlen(Key)]) % SIZE;
        tmp=S[i];
        S[i]=S[j];
        S[j]=tmp;
    }
}

unsigned char getByte(void)
{
    unsigned char tmp;
    i=(i+1)%SIZE;
    j=(j+S[i])%SIZE;
    tmp=S[i];
    S[i]=S[j];
    S[j]=tmp;
    return S[(S[i]+S[j])%SIZE];
}
void encrypt(char message[],int len)
{
   int index=0;
   char key[100];
   printf("Encrypting......");
   generateKey(key);
    while(index<strlen(message))
    {
        key[index]=getByte();
        message[index]=((unsigned char)message[index]^key[index]);
        index++;
    }
}
void decrypt(char message[],int len)
{
   int index=0;
   char key[100];
   printf("Decrypting......");
   generateKey(key);
    while(index<strlen(message))
    {
        key[index]=getByte();
        message[index]=((unsigned char)message[index]^key[index]);
        index++;
    }
}
int main(int argc,char *argv[])
{
   sgroup=atoi(argv[1]);
   slevel=atoi(argv[2]);
   struct sockaddr_in remoteSocketInfo;
   int sfd;
   int portNumber = 8081;
   if((sfd=socket(AF_INET, SOCK_STREAM, 0))<0)
   {
      close(sfd);
      exit(EXIT_FAILURE);
   }
   remoteSocketInfo.sin_family=AF_INET;
   remoteSocketInfo.sin_addr.s_addr=inet_addr("127.0.0.1");
   remoteSocketInfo.sin_port=htons(portNumber);
   
   if(connect(sfd,(struct sockaddr *)&remoteSocketInfo, sizeof(struct sockaddr_in)) < 0)
   {
      close(sfd);
      perror("NOT CONNECTED");
      exit(EXIT_FAILURE);
   }
   printf("Request Acknowledged\n");
   int rc=0;
   char buf[512];
   sprintf(buf,"%.2d%.2d",sgroup,slevel);
   printf("%s\n",buf);
   send(sfd,buf,strlen(buf),0);
   fd_set rfds;
   struct timeval tv;
   int ret,i;
   tv.tv_sec=1;
   tv.tv_usec=0;
   while(1)
   {
	//printf("%d\n",count);
	FD_ZERO(&rfds);
	int m=sfd>0?sfd:0;
	m+=1;
	FD_SET(0,&rfds);
	FD_SET(sfd,&rfds);
	ret=select(m,&rfds,NULL,NULL,&tv);
	if(ret>0)
	{
		if(FD_ISSET(0,&rfds))
		{
   			scanf("%s",buf);
            printf("Enter destination group and level : ");
            scanf("%d%d",&dgroup,&dlevel);
            if((dgroup!=sgroup)&&(dlevel!=slevel))
               encrypt(buf,strlen(buf));
            char msg[100];
            sprintf(msg,"%.2d%.2d%.2d%.2d%s",dgroup,dlevel,sgroup,slevel,buf);
            send(sfd,msg, strlen(msg)+1, 0);   
   	}
		if(FD_ISSET(sfd,&rfds))
		{
			   int rc=recv(sfd, buf, 512, 0);
            buf[rc]='\0';
			   
            char msg[100];
            for(i=0;i<=strlen(buf)-8;i++)
               msg[i]=buf[i+8];
            int group=10*(buf[4]-'0')+(buf[5]-'0');
            int level=10*(buf[6]-'0')+(buf[7]-'0');
            if((group!=sgroup)&&(level!=slevel))
               decrypt(msg,strlen(msg));
            printf("Recieved : %s\n",msg);
		}
	}
  }
   return 0;
}

