#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

//int main(int argc, char** argv)
int main()
{
	char *c;
	c = (char *)malloc(1 * sizeof(char));
	int fd1, fd2, sz;
	//fd is called file descripter same as file pointer
	
	fd1 = open("./files/src.txt", O_RDONLY);
	fd2 = open("./files/dest.txt", O_RDWR | O_CREAT | O_APPEND, 0644);
	
	printf("fd1 = %d, fd2 = %d\n", fd1, fd2);
	
	if(fd1 < 0 || fd2 < 0){
		printf("File opening failed");
	}
	else{
		while(read(fd1, c, 1)){
			sz = write(fd2, c, 1);
		}
	}
	
	close(fd1);
	close(fd2);
	
	return 0;
}
