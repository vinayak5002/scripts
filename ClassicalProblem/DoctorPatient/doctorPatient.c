# include<stdio.h>
# include<pthread.h>
# include<stdlib.h>
# include<unistd.h>
# include<ctype.h>
# include<sys/types.h>
# include<sys/wait.h>
# include<semaphore.h>
# include<sys/sem.h>

int sympV = 1, treatV = -1;

int symptoms, treatment;

int queue;

void *doctor(){
    int tempSymp;
    for(int i=0; i<queue; i++){

        // read symptoms
        while(sympV == 1);
        tempSymp = symptoms;
        sympV = 1;

        // write treatment
        while(treatV != -1);
        treatment = tempSymp * tempSymp;
        treatV = tempSymp;
    }

    pthread_exit(NULL);
}

void *patient(int symp){
    //write symptoms
    while(sympV == 0);
    symptoms = symp;
    sympV = 0;

    // note treatment
    while(treatV != symp);
    int myTreatment = treatment;
    treatV = -1;

    printf("Patient with symptoms %d treated with %d\n", symp, myTreatment);

    pthread_exit(NULL);
}

int main()
{
    printf("Enter number of patients: ");
    int n;
    scanf("%d", &n);
    queue = n;

    pthread_t doc, pat[n];

    if( pthread_create(&doc, NULL, doctor, NULL) != 0 ){ printf("Thread creation failed"); exit(1); }

    for(int i=0; i<n; i++){
        if ( pthread_create(&pat[i], NULL, patient, (int *) i) != 0 ){ printf("Thread creatino failed"); exit(1); }
    }

    if( pthread_join(doc, NULL) != 0 ){ printf("Thread join failed"); exit(1); }

    for(int i=0; i<n; i++){
        if( pthread_join(pat[i], NULL) != 0 ){ printf("Thread join failed"); exit(1); }
    }

    return 0;
}