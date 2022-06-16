# include<stdio.h>
# include<pthread.h>
# include<stdlib.h>
# include<unistd.h>
# include<ctype.h>
# include<sys/types.h>
# include<sys/wait.h>
# include<semaphore.h>
# include<sys/sem.h>

sem_t water, seeds, fertilizers;

void *farm(int num){
    for(int i=0; i<3; i++){
        sleep(num);

        sem_wait(&water);
        sem_wait(&seeds);
        sem_wait(&fertilizers);

        sleep(1);
        printf("Farmer number %d finished farming %d time\n", num, i+1);

        sem_post(&water);
        sem_post(&seeds);
        sem_post(&fertilizers);

    }
    pthread_exit(NULL);
}

int main(){
    pthread_t fam1, fam2, fam3;
    void *ret;

    if( (sem_init(&water, 0, 0))!=0 ){ printf("semaphore creation failed"); exit(1); }
    if( (sem_init(&seeds, 0, 0))!=0 ){ printf("semaphore creation failed"); exit(1); }
    if( (sem_init(&fertilizers, 0, 0))!=0 ){ printf("semaphore creation failed"); exit(1); }

    printf("Threads starting\n");

    sem_post(&water);
    sem_post(&seeds);
    sem_post(&fertilizers);

    if( (pthread_create(&fam1, NULL, farm, (int*) 1))!=0 ){ printf("Thread creation failed"); exit(1); }
    if( (pthread_create(&fam2, NULL, farm, (int*) 2))!=0 ){ printf("Thread creation failed"); exit(1); }
    if( (pthread_create(&fam3, NULL, farm, (int*) 3))!=0 ){ printf("Thread creation failed"); exit(1); }

    if( (pthread_join(fam1, NULL))!=0 ){ printf("Thread join failed"); exit(1); }
    if( (pthread_join(fam2, NULL))!=0 ){ printf("Thread join failed"); exit(1); }
    if( (pthread_join(fam3, NULL))!=0 ){ printf("Thread join failed"); exit(1); }

    if( (sem_destroy(&water)!=0) ){ printf("semaphore destruction failed"); exit(1); }
    if( (sem_destroy(&seeds)!=0) ){ printf("semaphore destruction failed"); exit(1); }
    if( (sem_destroy(&fertilizers)!=0) ){ printf("semaphore destruction failed"); exit(1); }

    exit(0);
}