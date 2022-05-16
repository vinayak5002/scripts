//SHMClient.C
 
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE     27
 
void die(char *s)
{
    perror(s);
    exit(1);
}

struct Book{
	int pages;
	char *title;
	int price;
};
 
int main()
{
    int shmid;
    key_t key;
    struct Book *shm, *s;
 
    key = 5678;
 
    if ((shmid = shmget(key, MAXSIZE, 0666)) < 0)
        die("shmget");
 
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1)
        die("shmat");
        
    s = shm;
 
    //Now read what the server put in the memory.
    printf("%s", s->title);
    
    s = NULL;
    
 	puts("\nClient exiting\n");
    exit(0);
}

