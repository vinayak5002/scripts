//SHMServer.C
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
 
#define MAXSIZE     27
 
void die(char *s)
{
    perror(s);
    exit(1);
}
 
int main()
{
    char c;
    int shmid;
    key_t key;
    char *shm, *s;
 
    key = 5678;
 
    if ((shmid = shmget(key, MAXSIZE, IPC_CREAT | 0666)) < 0)
        die("shmget");
 
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1)
        die("shmat");
 
    /*
     *      * Put text into the memory for the
     *        other process to read.
     *        */
    s = shm;
 
	printf("Enter input: ");
	gets(s);
 
    /*
     * Wait until the other process
     * changes the first character of our memory
     * to '*', indicating that it has read what
     * we put there.
     */
    while (*shm != '*'){puts("\nServer waiting\n");
        sleep(1);}
puts("\nServer exiting after client read data\n");
 
    exit(0);
}


