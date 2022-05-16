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
	printf("Message nor recived");
  exit(1);
}
 
struct Book{
	int price;
	int pages;
	char title[128];
};
 
typedef struct msgbuf1
{
    long    mtype;
	struct Book bookMsg;
}msgbuf;
 
 
void main()
{
    int msqid;
    key_t key;
    msgbuf rcvbuffer;
	size_t msgsz = sizeof(rcvbuffer);
 
    key = 1234;
 
    if ((msqid = msgget(key, 0666)) < 0)
      die("msgget()");
 
 
     //Receive an answer of message type 1.
    if (msgrcv(msqid, &rcvbuffer, msgsz, 1, 0) < 0)
      die("msgrcv");
    
    int pages = rcvbuffer.bookMsg.pages;
    int discount;
    
    //calculatie discount
    if(pages <= 300){
    	discount = 10;
    }
    else if (pages <= 500){
    	discount = 15;
    }
    else{
    	discount = 20;
    }
    
    printf("Number of pages in the book is %d and the total discount is %d", pages, discount);
	
	printf("\n");
	
    exit(0);
}

