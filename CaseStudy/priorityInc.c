#include <stdio.h>
#include <unistd.h>
#include <sched.h>

main()
{
    int policy = sched_getscheduler(0);

    int maxPriority = sched_get_priority_max(policy);

    struct sched_param sp;
    int ret;

    ret = sched_getparam(0, &sp);
    if(ret == -1){
        printf("sched_getparam failed\n");
        exit(1);
    }

    printf("Max priority that can be assigned to this process is %d and this processes priority is %d\n", maxPriority, sp.sched_priority);

    if(maxPriority == sp.sched_priority){
        printf("The process already has highed priority\n");
    }
    else{
        sp.sched_priority = maxPriority;
        
        printf("Updating this processes priority to %d\n");

        ret = sched_setscheduler(0, SCHED_FIFO, &sp);
        if(ret == -1){
            printf("Increasing priority failed\n");
            exit(1);
        }

        printf("update sucesses\n");
    }

    return 0;

}