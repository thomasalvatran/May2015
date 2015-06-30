#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <iostream>
using namespace std;

void *thread_func(void *arg);

char thread_msg[] = "Hello Thread !"; //global

int main(){
    int ret;
    pthread_t my_thread;
    void *ret_join;

    ret = pthread_create(&my_thread, NULL, thread_func, (void *) thread_msg);
    if (ret != 0){
        perror("pthread_create failed\n");
        exit(EXIT_FAILURE);
    }
    printf("Waiting for thread to finish...\n");
    ret = pthread_join(my_thread, &ret_join);
    if (ret != 0){
        perror("pthread_join failed");
        exit(EXIT_FAILURE);
    }
    printf("Thread joinded it returned %s\n", (char *) ret_join);
    printf("New thread message %s\n", thread_msg);
    exit(EXIT_SUCCESS);
 }

void *thread_func(void *arg)
{
    printf("This is thread_func(), arg is %s\n", (char*) arg);
    strcpy(thread_msg, "Bye");
//    pthread_exit("'test");
    char *p = "Exit from thread";
//    string p = "Exit from thread";
    pthread_exit(p);
}

