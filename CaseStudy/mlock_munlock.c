#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>

//This function will reserve "size" number of bytes and return a pointer it in
void * alloc_workbuf(size_t size)
{
    void *ptr;
    int retval;

    // for alligning the memory if the size is greater than page size
    retval = posix_memalign(&ptr, (size_t) sysconf(_SC_PAGESIZE), size);

    // return NULL on failure 
    if (retval)
        return NULL;

    // Actuall locking of memory
    if (mlock(ptr, size)) {
        free(ptr);
        return NULL;
    }
    return ptr;
}

void 
free_workbuf(void *ptr, size_t size)
{
    /* unlock the address range */
    munlock(ptr, size);

    /* free the memory */
    free(ptr);
}

int main()
{
    int *ptr;
    int n = 5, i;

    ptr = (int*) alloc_workbuf(n*sizeof(int));

    if(ptr == NULL){
        printf("Page locking failed\n");
        exit(1);
    }
    else{
        printf("Page locking sucessfull\n");

        for(int i=0; i<n; i++){
            ptr[i] = i+1;
        }

        printf("array stored in locked page\(s\) are:\n");

        for(int i=0; i<n; i++){
            printf("%d ", ptr[i]);
        }

        printf("\n");
    }

    return 0;
}