// http://www.bogotobogo.com/cplusplus/multithreading_pthread.php
//--semaphore with count called counting semaphore
// sem.c

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

void *thread_fnc(void * arg);

/* semaphores are declared global so they can be accessed
   in main() and in thread routine */
sem_t my_semaphore;
char my_string[100];  /* shared variable */

int main()
{
        int ret;
        int value;
        pthread_t my_thread;
        void *ret_join;

        /* initialize mutex to 1 - binary semaphore */
        /* second param = 0 - semaphore is local */
        ret = sem_init(&my_semaphore, 0, 0);

        sem_getvalue(&my_semaphore, &value);
        printf("The initial value of the semaphore is %d\n", value);

        if(ret != 0) {
                perror("semaphore init failed\n");
                exit(EXIT_FAILURE);
        }

        ret =  pthread_create(&my_thread, NULL, thread_fnc, NULL);
        if(ret != 0) {
                perror("pthread_create failed\n");
                exit(EXIT_FAILURE);
        }

        printf("Type in some characters. Enter 'quit' to finish\n");
        while(strncmp("quit", my_string, 4) != 0) {
                fgets(my_string, 100, stdin);
                sem_post(&my_semaphore);
                sem_getvalue(&my_semaphore, &value);
                printf("The value of the semaphore after sem_post() is %d\n", value);
        }
        printf("Waiting for thread to finish...\n");
        ret = pthread_join(my_thread, &ret_join);
        if(ret != 0) {
                perror("pthread_join failed");
                exit(EXIT_FAILURE);
        }
        printf("Thread joined, it returned %s\n", (char *) ret_join);
        sem_destroy(&my_semaphore);
        exit(EXIT_SUCCESS);
}

void *thread_fnc(void *arg)
{
        int val;

        printf("This is thread_fnc(), waiting for nonzero count...\n");
        sem_getvalue(&my_semaphore, &val);
        printf("The value of the semaphore in thread_fnc() is %d\n", val);
        sem_wait(&my_semaphore);
        sem_getvalue(&my_semaphore, &val);
        printf("The value of the semaphore after sem_wait() in thread_fnc() is %d\n", val);
        while(strncmp("quit", my_string, 4) != 0) {
                printf("You typed in %d characters\n",strlen(my_string)-1);
                sem_getvalue(&my_semaphore, &val);
                printf("The value of the semaphore before sem_wait() in thread_fnc() is %d\n", val);
                sem_wait(&my_semaphore);
                sem_getvalue(&my_semaphore, &val);
                printf("The value of the semaphore after sem_wait() in thread_fnc() is %d\n", val);
        }
        pthread_exit(NULL);
}
//http://www.bogotobogo.com/cplusplus/multithreading_pthread.php
//-- with semaphore and mutext and scope reduced to dead lock
//#include <pthread.h>
//#include <stdio.h>
//#include <semaphore.h>
//#include <stdlib.h>

//#define MAX 1

//int buffer[MAX];
//int fill = 0;
//int use  = 0;
//int loops = 0;

//sem_t empty;
//sem_t full;
//sem_t mutex;

//void put(int value) {
//    buffer[fill] = value;
//    fill = (fill + 1) % MAX;
//}

//int get() {
//    int b = buffer[use];
//    use = (use + 1) % MAX;
//    return b;
//}


//void *producer(void *arg) {
//    int i;
//    for (i = 0; i < loops; i++) {
//        sem_wait(&empty);
//        sem_wait(&mutex);   // semaphore then mutex othewise deadlock
//        put(i);
//        sem_post(&mutex);
//        sem_post(&full);
//    }
//}

//void *consumer(void *arg) {
//    int i;
//    for (i = 0; i < loops; i++) {
//        sem_wait(&full);
//        sem_wait(&mutex);
//        int b = get();
//        sem_post(&mutex);
//        sem_post(&empty);
//        printf("%d\n", b);
//    }
//}

//int main(int argc, char *argv[])
//{
//    printf("Deadlock if mutex is before semaphore scope\n");
//    printf("Mutex lock just before critical int b = get()\n");
//    if(argc < 2 ){
//        printf("Needs 2nd arg for loop count variable.\n");
//        return 1;
//    }

//    loops = atoi(argv[1]);

//    sem_init(&empty, 0, MAX); // MAX buffers are empty to begin with...
//    sem_init(&full, 0, 0);    // ... and 0 are full
//    sem_init(&mutex, 0, 1);    // mutex = 1 since it a lock

//    pthread_t pThread, cThread;
//    pthread_create(&pThread, 0, producer, 0);
//    pthread_create(&cThread, 0, consumer, 0);
//    pthread_join(pThread, NULL);
//    pthread_join(cThread, NULL);
//    return 0;
//}
//---with semaphore and mutex for race condition
//#include <pthread.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <semaphore.h>
//#include <pthread.h>
//#include <stdio.h>
//#include <semaphore.h>

//#define MAX 1

//int buffer[MAX];
//int fill = 0;
//int use  = 0;
//int loops = 0;
//sem_t empty;
//sem_t full;
//sem_t mutex;
//pthread_mutex_t mutex1;

//void put(int value) {
//    buffer[fill] = value;
//    fill = (fill + 1) % MAX;
//}

//int get() {
//    int b = buffer[use];
//    use = (use + 1) % MAX;
//    return b;
//}


//void *producer(void *arg) {
//    int i;
//    for (i = 0; i < loops; i++) {  //scope reduction
//        sem_wait(&empty);   // these order semaphore
//        sem_wait(&mutex);   // then mutex
//        pthread_mutex_lock(&mutex1); // lock otherwise deadlock
//        put(i);
//        pthread_mutex_unlock(&mutex1);
//        sem_post(&mutex);
//        sem_post(&full);
//    }
//}

//void *consumer(void *arg) {
//    int i;
//    for (i = 0; i < loops; i++) {
//        sem_wait(&full);
//        sem_wait(&mutex);
//        pthread_mutex_lock(&mutex1);
//        int b = get();
//        pthread_mutex_unlock(&mutex1);
//        sem_post(&mutex);
//        sem_post(&empty);
//        printf("%d\n", b);
//    }
//}

//int main(int argc, char *argv[])
//{
//    if(argc < 2 ){
//        printf("Needs 2nd arg for loop count variable.\n");
//        return 1;
//    }

//    loops = atoi(argv[1]);

//    sem_init(&empty, 0, MAX); // MAX buffers are empty to begin with...
//    sem_init(&full, 0, 0);    // ... and 0 are full
//    sem_init(&mutex, 0, 1);    // mutex = 1 since it a lock

//    pthread_t pThread, cThread;
//    pthread_create(&pThread, 0, producer, 0);
//    pthread_create(&cThread, 0, consumer, 0);
//    pthread_join(pThread, NULL);
//    pthread_join(cThread, NULL);
//    return 0;
//}
//---with semaphore
//#include <pthread.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <semaphore.h>

//#define MAX 1

//int buffer[MAX];
//int fill = 0;
//int use = 0;
//int loops = 0;
//sem_t empty;
//sem_t full;

//void put(int value) {
//  buffer[fill] = value;
//  fill = (fill + 1) % MAX;
//}

//int get() {
//  int tmp = buffer[use];
//  use = (use + 1) % MAX;
//  return tmp;
//}

//void *producer(void *arg) {
//  int i;
//  for (i = 0; i < loops; i++) {
//    sem_wait(&empty);
//    put(i);
//    sem_post(&full);
//  }
//}

//void *consumer(void *arg) {
//  int i;
//  for (i = 0; i < loops; i++) {
//    sem_wait(&full);
//    int b = get();
//    sem_post(&empty);
//    printf("%d\n", b);
//  }
//}

//int main(int argc, char *argv[]) {

//  if (argc < 2) {
//    printf("Needs 2nd arg for loop count variable.\n");
//    return 1;
//  }

//  loops = atoi(argv[1]);

//  sem_init(&empty, 0, MAX); // MAX buffers are empty to begin with...1
//  sem_init(&full, 0, 0);    // ... and 0 are full

//  pthread_t pThread, cThread;
//  pthread_create(&pThread, 0, producer, 0);
//  pthread_create(&cThread, 0, consumer, 0);
//  pthread_join(pThread, NULL);
//  pthread_join(cThread, NULL);
//  return 0;
//}
//----------------- no semaphore
//#include <pthread.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <semaphore.h>

//#define MAX 100

//int buffer[MAX];
//int fill = 0;
//int use  = 0;

//void put(int value) {
//    buffer[fill] = value;
//    fill = (fill + 1) % MAX;
//}

//int get() {
//    int tmp = buffer[use];
//    use = (use + 1) % MAX;
//    return tmp;
//}

//int loops = 0;

//void *producer(void *arg)
//{
//    int i;
//    for (i = 0; i < loops; i++) {
//        put(i);
//    }
//}

//void *consumer(void *arg) {
//    int i;
//    for (i = 0; i < loops; i++) {
//        int b = get();
//        printf("%d\n", b);
//    }
//}

//int main(int argc, char *argv[])
//{

//    if(argc < 2 ){
//        printf("Needs 2nd arg for loop count variable.\n");
//        return 1;
//    }

//    loops = atoi(argv[1]);

//    pthread_t pThread, cThread;
//    pthread_create(&pThread, 0, producer, 0);
//    pthread_create(&cThread, 0, consumer, 0);
//    pthread_join(pThread, NULL);
//    pthread_join(cThread, NULL);
//    return 0;
//}
