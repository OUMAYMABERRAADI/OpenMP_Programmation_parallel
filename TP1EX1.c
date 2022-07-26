#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#ifndef NUM_THREADS
#define NUM_THREADS 10
#endif

int i =-1;

void *affiche(void *threadid) {
    long tid;
    tid = (long)threadid;
    if(i == tid -1 )
    {
       printf("je suis processeur %ld  i= %d\n", tid, i);
       i++;
    } 
    else{      
      i++;
      printf("non prise en charge\n");
    pthread_exit(NULL);
    }
}


int main(int argc, char const *argv[]) {
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;

    for (t = 0; t < NUM_THREADS; t++) {
        rc = pthread_create(&threads[t], NULL, affiche, (void *)t);
        if (rc) {
            printf("ERORR; return code from pthread_create() is %d\n", rc);
            exit(EXIT_FAILURE);
        }
    }
    pthread_exit(NULL);
    return 0;
}
