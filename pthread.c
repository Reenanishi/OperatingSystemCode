#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/* The "thread function" passed to pthread_create.  Each thread executes this
 * function and terminates when it returns from this function. */
void *HelloWorld(void *id) {
    long *myid = (long *) id;
    printf("I am thread %ld\n", *myid+1);
    return NULL;
}

int main(int argc, char **argv) {
    int i;
    int nthreads = 8; //number of threads
    pthread_t *thread_array; //pointer to future thread array
    long *thread_ids;

    // Allocate space for thread structs and identifiers.
    thread_array = malloc(nthreads * sizeof(pthread_t));
    thread_ids = malloc(nthreads * sizeof(long));

    // Assign each thread an ID and create all the threads.
    for (i = 0; i < nthreads; i++) {
        thread_ids[i] = i;
        pthread_create(&thread_array[i], NULL, HelloWorld, &thread_ids[i]);
    }

    /* Join all the threads. Main will pause in this loop until all threads
     * have returned from the thread function. */
    for (i = 0; i < nthreads; i++) {
        pthread_join(thread_array[i], NULL);
    }

    free(thread_array);
    free(thread_ids);
    return 0;
}