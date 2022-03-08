#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int global_var = 0;
/*
* Function used to protect a global variable used in the function inc().
*
* @inc : the function that must be called in critical (= protected) section
* @nb : the number of times the function inc() has to be called
* @mutex : an initialised mutex that has to be used for the protection
*
* @return 0 if no error, -1 otherwise
*/
int protect(void inc(void), int nb, pthread_mutex_t* mutex){
    for (int i=0; i < nb; i++) {
        int rc = 0;
        if (0 != (rc = pthread_mutex_lock(mutex))) return -1;
        inc();
        if (0 != (rc = pthread_mutex_unlock(mutex))) return -1;
    }
    return 0;
}

void increment_global_var(void) {

    global_var++;
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
