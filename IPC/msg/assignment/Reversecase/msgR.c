//IPC_msgq_rcv.c
 
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
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
    
    char *msg = rcvbuffer.mtext;
    char res[128];
    int p=0;
    
    for(int i=0; msg[i] !=  '\0'; i++){
    	if(isupper(msg[i])){
    		res[p] = tolower(msg[i]);
    	}
    	else if(islower(msg[i])){
    		res[p] = toupper(msg[i]);
    	}
    	else{
    		res[i] = msg[i];
    	}
    	
    	p++;
    }
 
	for(int i=0; i<=p; i++){
		printf("%c", res[i]);
	}



	printf("\n");

	//Normals:
	//printf("%s", rcvbuffer.mtext);
	
    exit(0);
}

