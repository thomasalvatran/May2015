//home/tovantran/Ctest/May31StackArray.cpp --> 2015-06-01 by ./.tv  owner: tovantran
// youtube: myschoolcode stack implement on head(top) no traverse to end
#include <stdio.h>
#define SIZE 101
int arr[SIZE];
int top = -1;
void push(int x) {
  if (top == SIZE -1){
      printf("Error: stack is full\n");
      return;
  }
  arr[++top] = x;
}
void pop() {
  if (top == -1) {
    printf("Error: no element to pop\n");
    return;
  }
  top--;
}
int getTop(){
    return arr[top];
}
void print(){
    int i;
    printf("Stack: ");
    for (i = 0; i <= top; i++ )
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    push(2);print();
    push(5);print();
    push(55);print();
    pop(); print();
    printf("%d\n ",getTop());
}

