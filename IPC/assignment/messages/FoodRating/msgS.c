#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void die(char *s){
	perror(s);
	exit(1);
}

struct ResDetails{
	int tasteRating;
	int cleanlinessRating;
	int priceRating;
};

void getResDetails(struct ResDetails *get){
	printf("Enter Food taste rating: ");
	scanf("%d", &get->tasteRating);
	
	printf("Enter restaurant cleaniness rating: ");
	scanf("%d", &get->cleanlinessRating);
	
	printf("Enter food price ratings: ");
	scanf("%d", &get->priceRating);
}

struct Msgbuf{
	long mtype;
	struct ResDetails detailsBuff;
};

void main(){
	int mqid;
	key_t key;
	struct Msgbuf msgbuf;
	
	key = 1234;
	
	if((mqid = msgget(key, IPC_CREAT | 0666)) <0){
		die("msgget");
	}
	
	msgbuf.mtype = 1;
	
	printf("Enter restraunts ratings: \n");
	getResDetails(&msgbuf.detailsBuff);
	
	if(msgsnd(mqid, &msgbuf, sizeof(msgbuf.detailsBuff), IPC_NOWAIT) < 0){
		printf("Message sending failed");
		die("msgsnd");
	}
	else{
		printf("Message sent");
	}
	
	exit(0);
}
