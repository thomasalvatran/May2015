//Bogotobogo.com
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int sum(int);

typedef struct {
  int *a;
  int length;
  int sum;
} MyData;

#define N 5
#define L 20

MyData mData;
pthread_t myThread[N];
pthread_mutex_t mutex;

void *threadWork(void *arg) {
  /* Define and use local variables for convenience */
  long offset = (long)arg;
  int sum = 0;
  int start = offset * mData.length;
  int end = start + mData.length;

  /* each thread calculates its sum */
  for (int i = start; i < end; i++)
    sum += mData.a[i];

  /* mutex lock/unlock */
  pthread_mutex_lock(&mutex);
  mData.sum += sum;
  pthread_mutex_unlock(&mutex);

  pthread_exit((void *)0);
}

int main() {
  void *status;

  /* fill the structure */
  int *a = (int *)malloc(N * L * sizeof(int));
  for (int i = 0; i < N * L; i++)
    a[i] = i + 1;
  mData.length = L;
  mData.a = a;
  mData.sum = 0;

  pthread_mutex_init(&mutex, NULL);

  /* Each thread has its own set of data to work on. */
  for (long i = 0; i < N; i++)
    pthread_create(&myThread[i], NULL, threadWork, (void *)i);

  /* Wait on child threads */
  for (int i = 0; i < N; i++)
    pthread_join(myThread[i], &status);

  /* Results and cleanup */
  printf("Sum = %d \n", mData.sum);
  free(a);
  printf("Sum = %d\n", sum(100));  /* Check is mData.sum is correct */

  pthread_mutex_destroy(&mutex);
  pthread_exit(NULL);

}
int sum(int a){
 if ( a > 1)
        return (a + sum(a - 1));
 else
      return 1;
}
// www.bogotobogo.com/cplusplus/mutltithreading_pthread.php Synchronization
// Pthread
// volatile int counter = 0; //ensure read from memory for each access
// pthread_mutex_t myMutex; //mutex variable

// void *mutex_testing(void *param) {
//  int i;
//  for (i = 0; i < 5; i++) {
//    pthread_mutex_lock(&myMutex);  //disable all others threads during
//    critical
//    counter++;
//    usleep(1);  //delay for longer duration when acquire mutex to simulate
//    printf("thread %d counter = %d\n", (int *)param, counter);
//    pthread_mutex_unlock(&myMutex); //enable threads again
//  }
//}

// int main() {
//  int one = 1, two = 2, three = 3;
//  pthread_t thread1, thread2, thread3;
//  pthread_mutex_init(&myMutex, 0);
//  pthread_create(&thread1, 0, mutex_testing, (void *)one);
//  pthread_create(&thread2, 0, mutex_testing, (void *)two);
//  pthread_create(&thread3, 0, mutex_testing, (void *)three);
//  pthread_join(thread1, 0); //start threads in order one by one
//  pthread_join(thread2, 0);
//  pthread_join(thread3, 0);
//  pthread_mutex_destroy(&myMutex);
//  return 0;
//}

