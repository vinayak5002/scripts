#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

//int main(int argc, char** argv)
int main()
{
	char *c;
	c = (char *)malloc(100 * sizeof(char));
	int fd, sz;
	//fd is called file descripter same as file pointer
	
	fd = open("./files/readFile.txt", O_RDONLY);
	
	printf("fd = %d\n", fd);
	
	if(fd < 0){
		printf("File opening failed");
	}
	else{
		// To read file using malloc
		/*
		sz = read(fd, c, 100);
		printf("called sz = read(fd, c, 100) and we get sz = %d\n\n", sz);
		c[sz] = '\0';
		printf("File content which was read is \n%s\n", c);
		*/
		
		//To read till end of the file using the loop:
		
		while(read(fd, c, 1)){
			printf("%c", *c);
		}
	}
	
	close(fd);
	
	return 0;
}
