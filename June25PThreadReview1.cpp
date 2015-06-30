// www.bogotobogo.com/cplusplus/multithreading_pthread.php
// Linux advanced programming p.89
//~/Ctest/k_r
// Single Thread
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
//#include <unistd.h> //sleep(100);

struct Node {
  int thread_id;
  int count;
  char data;
};

//-------------------------------------- &funtion, (void *)id (void pointer)
void *worker_thread(void *arg) {
  struct Node *p = (struct Node *)arg;
  printf("This is worker_thread() -> %d\n", p->thread_id);
  for (int i = 0; i < p->count; i++)
    printf("Node data = %c\n", p->data);
  pthread_exit(NULL);
}

int main() {
  pthread_t thread1_id;
  pthread_t thread2_id;
  struct Node thread1_args, thread2_args;
  int ret;
  printf("In main: creating thread\n");
  thread1_args.thread_id = 1; // init struct
  thread1_args.count = 10;
  thread1_args.data = 'a';
  ret = pthread_create(&thread1_id, NULL, &worker_thread, &thread1_args);
  thread2_args = {2, 10, 'b'}; // init struct
  ret = pthread_create(&thread2_id, NULL, &worker_thread, &thread2_args);
  pthread_join(thread2_id, NULL);
  pthread_join(thread1_id, NULL);

  if (ret != 0) {
    printf("Error: pthread_created() failed\n");
    exit(EXIT_FAILURE);
  }
  pthread_exit(NULL);
}

////Dec 6, 2013
////http://www.cs.cmu.edu/afs/cs/academic/class/15492-f07/www/pthreads.html
//#include <stdio.h>
//#include <stdlib.h>
//#include <pthread.h>

// void *print_message_function( void *ptr );

// main()
//{
//     pthread_t thread1, thread2;
//     char *message1 = "Thread 1";
//     char *message2 = "Thread 2";
//     int  iret1, iret2;

//    /* Create independent threads each of which will execute function */

//     iret1 = pthread_create( &thread1, NULL, print_message_function, (void*)
//     message1);
//     iret2 = pthread_create( &thread2, NULL, print_message_function, (void*)
//     message2);

//     /* Wait till threads are complete before main continues. Unless we  */
//     /* wait we run the risk of executing an exit which will terminate   */
//     /* the process and all threads before the threads have completed.   */

//     pthread_join( thread1, NULL);
//     pthread_join( thread2, NULL);

//     printf("Thread 1 returns: %d\n",iret1);
//     printf("Thread 2 returns: %d\n",iret2);
//     exit(0);
//}

// void *print_message_function( void *ptr )
//{
//     char *message;
//     message = (char *) ptr;
//     printf("%s \n", message);
//}

