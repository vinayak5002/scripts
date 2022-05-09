//IPC_msgq_rcv.c
 
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE     128

void die(char *s)
{
  perror(s);
  exit(1);
}
 
typedef struct msgbuf1
{
    long    mtype;
    char    mtext[MAXSIZE];
}msgbuf ;
 
 
void main()
{
    int msqid;
    key_t key;
    msgbuf rcvbuffer;
 
    key = 1234;
 
    if ((msqid = msgget(key, 0666)) < 0)
      die("msgget()");
 
 
     //Receive an answer of message type 1.
    if (msgrcv(msqid, &rcvbuffer, MAXSIZE, 1, 0) < 0)
      die("msgrcv");
    
    //Vowels:  
    char vow[128];
    int p=0;
    
    for(int i=0; rcvbuffer.mtext[i] !=  '\0'; i++){
      if(rcvbuffer.mtext[i] == 'a' | rcvbuffer.mtext[i] == 'e' | rcvbuffer.mtext[i] == 'i' | rcvbuffer.mtext[i] == 'o' | rcvbuffer.mtext[i] == 'u'){
        vow[p] = rcvbuffer.mtext[i];
        p++;
      }
    }
 
	for(int i=0; i<=p; i++){
		printf(" %c", vow[i]);
	}

	
	
	printf("\n");
	
	//Normals:
	//printf("%s", rcvbuffer.mtext);
	
    exit(0);
}

