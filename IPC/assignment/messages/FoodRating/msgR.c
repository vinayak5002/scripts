/*
	
	define msg structure and passign structure
	
	creat queue and get its id using key and 0666
	
	recive message msrcv (,qid, &buffer, size of buffer, 1, 0)
	
*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>


void die(char *s){
	perror(s);
	printf("Message not recived");
	exit(1);
}

struct ResDetails{
	int tasteRating;
	int cleanlinessRating;
	int priceRating;
};

struct msgbuff{
	long mtype;
	struct ResDetails detailsBuff;
};


int main(){
	int mqid;
	key_t key;
	struct msgbuff rcvbuff;
	struct ResDetails rcvDetails;
	
	key = 1234;
	
	if((mqid = msgget(key, 0666)) < 0){
		die("msgget()");
	}
	
	if(msgrcv(mqid, &rcvbuff, sizeof(rcvbuff), 1, 0) < 0){
		die("msgrcv()");
	}
	
	rcvDetails = rcvbuff.detailsBuff;
	
	if(rcvDetails.tasteRating>=6 && rcvDetails.cleanlinessRating>=6 && rcvDetails.priceRating>=6){
		printf("Restraunt has passed");
	}
	else{
		printf("Restraunt has failed");
	}
	
	exit(0);

}
