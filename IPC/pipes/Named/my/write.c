#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 


int main()
{	
	int fd;
	char *fifoPath = "/home/vinayak/Documents/scripts/IPC/pipes/Named/my/vin.txt";
	char *writeBuff = "Hello, I am vinayak\n\0";
	
	mkfifo(fifoPath, 0666|O_CREAT);
	
	fd = open(fifoPath, O_WRONLY);
	
	write(fd, writeBuff, sizeof(writeBuff));
	
	printf("Message written to reader\n");
	
	close(fd);

	return 0;
}
