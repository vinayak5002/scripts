//IPC_msgq_send.c
 
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE     128
 
void die(char *s)
{
  perror(s);
  exit(1);
}

struct Book{
	int price;
	int pages;
	char title;
};

//getting input of the book details
void getBook(struct Book *bookObj){
	printf("Enter title of the book: ");
	scanf("%s", &bookObj->title);

	//strcpy(bookObj->title, "None\0");
	
	printf("Enter price of the book: ");
	scanf("%d", &bookObj->price);
	
	printf("Enter  no. of pages in the book: ");
	scanf("%d", &bookObj->pages);
}
 
typedef struct msgbuf1
{
    long    mtype;
    struct Book bookMsg;
}msgbuf;
 
void main()
{
    int msqid;
    int msgflg = IPC_CREAT | 0666;
    key_t key;
    msgbuf sbuf;
    struct Book bookObj;
 
    key = 1234;
 
    if ((msqid = msgget(key, msgflg )) < 0)   //Get the message queue ID for the given key
      die("msgget");
 
    //Message Type
    sbuf.mtype = 1;
 
    printf("Enter a details of the book to add to message queue : \n");
    getBook(&sbuf.bookMsg);
 
    if (msgsnd(msqid, &sbuf, sizeof(bookObj), IPC_NOWAIT) < 0)
    {
        printf ("%d, %ld, %ld\n", msqid, sbuf.mtype, sizeof(bookObj));
        die("msgsnd");
    }
 
    else
        printf("Message Sent\n");
 
    exit(0);
}

