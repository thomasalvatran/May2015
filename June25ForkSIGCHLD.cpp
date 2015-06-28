#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// www.bogotobogo.com/cplusplus/mutltithreading_pthread.php
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 150

int main() {
  int pid = fork();
  char buf[BUF_SIZE];
  int print_count;

  switch (pid) {
  case -1:
    perror("fork failed");
    exit(1);
  case 0:
    print_count = 10;
    sprintf(buf, "child process: pid = %d", pid);
    break;
  default:
    print_count = 5;
    sprintf(buf, "parent process: pid = %d", getpid());
    break;
  }

  if (pid) {
    printf("Parent process...%d\n", getpid());
    int status;
    int pid_child = wait(&status);
  }
  for (; print_count > 0; print_count--)
    puts(buf);
  exit(0);
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
// Randomly count if no pthread_mutex_lock
// thread 1 counter = 1
// thread 1 counter = 3
// thread 1 counter = 4
// thread 1 counter = 5
// thread 1 counter = 6
// thread 2 counter = 2
// thread 2 counter = 7
// thread 2 counter = 8
// thread 2 counter = 9
// thread 2 counter = 10
// thread 3 counter = 11
// thread 3 counter = 12
// thread 3 counter = 13
// thread 3 counter = 14
// thread 3 counter = 15
// thread finished before another thread start like join
// thread 3 counter = 1
// thread 3 counter = 2
// thread 3 counter = 3
// thread 3 counter = 4
// thread 3 counter = 5
// thread 2 counter = 6
// thread 2 counter = 7
// thread 2 counter = 8
// thread 2 counter = 9
// thread 2 counter = 10
// thread 1 counter = 11
// thread 1 counter = 12
// thread 1 counter = 13
// thread 1 counter = 14
// thread 1 counter = 15
// linuxquestion.org how a father process know which child process and the
// signal SIGCHLD
// void handler(int sig) {
//  pid_t pid;

//  pid = wait(NULL);

//  printf("Pid %d exited.\n", pid);
//}

// int main(void) {
//  signal(SIGCHLD, handler);

//  if (!fork()) {
//    printf("Child pid is %d\n", getpid());
//    exit(0);
//  }
//  sleep(10);
//  printf("Parent pid is %d\n", getpid());

//  getchar();
//  return 0;
//}

// stackoverflow.com Signal and SIGCHLD, waht does it do?

//#define N 4
// int val = 9;
// void handler(int sig) {
//  val += 3;
//  return;
//}
// int main() {
//  pid_t pid;
//  int i;
//  signal(SIGCHLD, handler);

//  for (i = 0; i < N; i++) {
//    if (!fork()) {
//      val -= 3;
//      exit(0);
//    }
//  }

//  for (i = 0; i < N; i++) {
//    waitpid(-1, NULL, 0);
//  }
//  printf("val = %d\n", val);
//}

