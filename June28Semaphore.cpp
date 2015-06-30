#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

//pthread_mutex_t mutex;

//void *f1(void *arg)
//{
//        printf("thread 1\n");
//}

//void *f2(void *arg)
//{
//        pthread_mutex_lock(&mutex);     //won't solve
//        printf("thread 2\n");
//        pthread_mutex_unlock(&mutex);
//}

//int main()
//{
//        pthread_t myThread[2];
//        pthread_create(&myThread[0], 0, f1, 0);
//        pthread_create(&myThread[1], 0, f2, 0);
//        pthread_join(myThread[1], 0);   //won't solve
//        pthread_join(myThread[0], 0);
//        return 0;
//}
//thread 1
//thread 2

#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>

sem_t mySemaphore;

void *f1(void *param)
{
        sem_wait(&mySemaphore);
        printf("thread %d\n", (long)param);
        // signal semaphore
        // increment the value of mySemaphore by 1
        // if there are one or more threads waiting, wake
}

void *f2(void *param)
{
        // wait until value of semaphore is greater than 0
        // decrement the value of semaphore by 1

        printf("thread %d\n", (long)param);
        sem_post(&mySemaphore);
}

int main()
{
        pthread_t myThread[2];

        // The 3rd value which is semaphore count set to 0
        sem_init(&mySemaphore, 0, 0);

        long one = 1, two = 2;

        // f2 has sem_wait(), so it should wait
        // until f1 increase the semaphore value to 1
        // As a result, f1 will be executed first
        pthread_create(&myThread[0], 0, f1, (void *)one);
        pthread_create(&myThread[1], 0, f2, (void *)two);

        pthread_join(myThread[0], 0); // even f1 first but will wait
        pthread_join(myThread[1], 0);
        sem_destroy(&mySemaphore);
        return 0;
}
//thread 2
//thread 1

