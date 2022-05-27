/* Usage of pthread library*/
#include <pthread.h>
#include <stdio.h>
#include<stdlib.h>
#define NUM_THREADS 5 

void *PrintHello(void *threadid) {
   int tid;
   tid = (int)threadid;
   printf("Hello World! It's me, thread #%d!\n", tid);
   pthread_exit(NULL);
}

int main (int argc, char *argv[])
{
	pthread_t threads[NUM_THREADS];
	int rc, t;
	
	for(t=0; t<NUM_THREADS; t++)
	{
		printf("In main: creating thread %d\n", t);
		rc = pthread_create(&threads[t], NULL, PrintHello, (void *)t);
		/*
		int pthread_create(
			pthread_t *thread,
			const pthread_attr_t *attr,
			void *(*start_routine) (void *),
			void *arg
		);
		user vs kernel
		mapping both
		use of sheduler activation
		*/
	
		if (rc){
			printf("ERROR; return code from pthread_create() is %d\n", rc);
			exit(-1);       
		}
	}
}

/*
when linking with library, give -lpthrea or -pthread option
*/
