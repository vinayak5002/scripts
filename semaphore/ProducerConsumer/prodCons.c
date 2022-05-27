/*Semaphore + pthread demo*/
#include<pthread.h>
#include<stdio.h>
#include<semaphore.h>
#include<unistd.h>
void *producer();
void *consumer();
int units=1; //shared variable
sem_t s; //semaphore variable

int main()
{
    sem_init(&s,0,1); /*initialize semaphore variable - 1st argument is address of variable, 2nd is number of processes sharing semaphore, 3rd argument is the initial value of semaphore variable*/
    pthread_t thread1, thread2;
    //Thread creation
    pthread_create(&thread1, NULL, producer, NULL);
    sleep(100);
    pthread_create(&thread2, NULL, consumer, NULL);

    /*The pthread_join() function shall suspend execution of the calling thread until the target thread terminates*/
    pthread_join(thread1, NULL);
    pthread_join(thread2,NULL);

    printf("Final value of shared is %d\n",units); //prints the last updated value of shared variable
}

void *producer()
{
    while(1){
        int x;
        sem_wait(&s);

        x = units;
        printf("Producer : Units present are: %d\n", x);

        if(x+1 <= 10){
            x++;
            printf("one more unit is producer\n");

            sleep(1);

            units = x;

            printf("Buffer updated\n");
        }

        sem_post(&s);
    }
    
}


void *consumer()
{
    while(1){
        int x;
        sem_wait(&s);

        x = units;
        printf("Consumer : Units present are: %d\n", x);

        if(x <= 1){
            x--;
            printf("one unit is consumed by consumer\n");

            sleep(1);

            units = x;

            printf("Buffer updated\n");
        }

        sem_post(&s);
    }

}