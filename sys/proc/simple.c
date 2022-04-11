#include <unistd.h>
#include <stdio.h>

int main() 
{
	pid_t pid;
	
	pid = fork();
	printf("fork called\n");
	
	if(pid != 0){
		sleep(2);
		printf("Parent process\n");
	}
	else{
		sleep(3);
		printf("Child process\n");
		while(1){}
	}
	
	return 0;
}
