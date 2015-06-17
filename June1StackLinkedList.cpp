//home/tovantran/Ctest/June1StackLinkedList.cpp --> 2015-06-01 by ./.tv  owner: tovantran
// youtube: myschoolcode stack implement on head(top) no traverse to end
#include <stdio.h>
#include <malloc.h>

struct Node {
  int data;
  struct Node *next;
};
struct Node *top = NULL; // head
void push(int x) {
  struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
  temp->next = top; //next node is 0
  temp->data = x;
  top = temp;
}
void pop() {
  struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
  if (top == NULL)
    return;
  temp = top;
  top = top->next;
  free(temp);
}
int getTop(){
    return top->data;
}
void print(){
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp = top;
    printf("Stack: ");
    while(temp != NULL){
        printf("%d ", temp->data );
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    push(2); print();
    push(5); print();
    push(15); print();
    pop(); print();
}

