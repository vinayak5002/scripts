#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <stdlib.h>

int main()
{
	int fdpipe[2];
	int pid;
	int pipeReturnStatus;
	
	pipeReturnStatus = pipe(fdpipe);
	
	if(pipeReturnStatus == -1){
		printf("Unable to create pipe\n");
		exit(1);
	}
	
	pid = fork();
	
	//parent
	if(pid != 0){
		wait(NULL);
		printf("\nParent process reading from child\n");
		char *readBuff;
		read(fdpipe[0], &readBuff, sizeof(readBuff));
		
		printf("Recived message from child: %s\n", readBuff);
	}
	//child
	else{
		char s;
		printf("Enter message from child: ");
		scanf("%s", &s);
		printf("Child writing message \%s\n", s);
		write(fdpipe[1], s, sizeof(s));
	}
	
	return 0;	

}
