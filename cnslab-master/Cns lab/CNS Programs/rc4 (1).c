#include<stdio.h>
#include<string.h>
#define SIZE 256
unsigned char S[SIZE];
int i,j;
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
int main(int argc, unsigned char **argv)
{
    int in;
    unsigned char message[]="ABCDEF GHIKJ\nKHJHJGJHGJ",encoded_msg[1024],decoded_msg[1024],key[1024];
    int index=0;
    generateKey(argv[1]);
    while(index<strlen(message))
    {
        key[index]=getByte();
        encoded_msg[index]=((unsigned char)message[index]^key[index]);
        index++;
    }
    printf("ENCODED MESSAGE\n");
    for(i=0;i<strlen(message);i++)
        printf("%c",encoded_msg[i]);
    printf("\n");
    for(i=0;i<strlen(message);i++)
        decoded_msg[i]=encoded_msg[i]^key[i];

    printf("DECODED MESSAGE\n");
    for(i=0;i<strlen(message);i++)
        printf("%c",decoded_msg[i]);
    printf("\n");
    return 0;
}
