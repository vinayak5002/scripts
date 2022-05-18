#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <stdlib.h>

int main()
{
	char *fifoPath = "/home/vinayak/Documents/scripts/IPC/pipes/Named/my/vin.txt";
	int fd;
	char *readBuff;
	
	mkfifo(fifoPath, 0666);
	
	fd = open(fifoPath, O_RDONLY);
	
	if((read(fd, readBuff, 128)) < 0){
		printf("Couldn't Read\n");
		exit(1);
	}
	
	printf("Read from writer: %s", readBuff);
	
	close(fd);
	
	return 0;
}
