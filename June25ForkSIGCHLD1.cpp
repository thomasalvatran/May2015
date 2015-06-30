#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>

int main()
{
   int status;
   pid_t pid = fork();

   // Child process will sleep for 10 second
   if(pid == 0)
   {
      execl("/usr/bin/sleep", "/usr/bin/sleep", 10, NULL);
   }
   // Parent process will wait for child process to terminate
   // Then, it will report the exit status of the child process
   else
   {
      waitpid(pid, &status, 0);
      printf("status = %d\n", status);  // print out ->  status = 65280
   }
}
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

