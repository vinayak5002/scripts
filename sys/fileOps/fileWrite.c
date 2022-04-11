#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

//int main(int argc, char** argv)
int main()
{
	char writeThis[40] = "This text is from writeFile.c\n\0";
	int fd, sz;
	//fd is called file descripter same as file pointer
	
	fd = open("./files/fileWrite.txt", O_RDWR | O_CREAT | O_APPEND, 0644);
	
	printf("fd = %d\n", fd);
	
	if(fd < 0){
		printf("File opening failed");
	}
	else{
		
		sz = write(fd, writeThis, strlen(writeThis));
		printf("sz = %d", sz);
	}
	
	close(fd);
	
	return 0;
}
