#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>

sem_t s;

void * task(void *param)
{
    printf("%s done its task \n", (char *)param);

    // signaling worker's task (printing) is done
    sem_post(&s);

    return NULL;
}

int main()
{
    // set current semaphore value 0 (the 3rd arg)
    sem_init(&s, 0, 0);

    printf("main thread started\n");

    pthread_t worker;
    pthread_create(&worker, 0, task, (void*)"worker thread");

    // wait here for worker thread to finish
    sem_wait(&s);

    printf("main thread ends here\n");

    return 0;
}

