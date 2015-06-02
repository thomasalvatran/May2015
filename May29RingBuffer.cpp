//myschoolcode
#include <stdlib.h>
#include <iostream>
using namespace std;

#define SIZE 10
int rear = -1, front = -1;
int a[10];
bool isFull() { return ((rear + 1) % SIZE == front); }
bool isEmpty() { return (rear == front); }
void enqueue(int i) {
  if (isFull())
    return;

    rear = (rear + 1) % SIZE;
    a[rear] = i;

}
void dequeue() {
  if (isEmpty() == true)
    return;
  front = (front + 1) % SIZE;
  a[front] = -1;
}
void print() {
  for (int i = 0; i < SIZE; i++)
    cout << a[i] << " ";
  cout << endl;
}

int main() {
  enqueue(111);
  enqueue(222);
  enqueue(111);
  enqueue(222);
  enqueue(111);
  enqueue(222);
  enqueue(0);
  enqueue(1);
  enqueue(2);
//  enqueue(3);
//  enqueue(4);
  // dequeue();
  print();
  cout << "rear = " << rear << " front = " << front << endl;
  for (int i = 0; i < SIZE; i++)
    dequeue();
  print();
  cout << "rear = " << rear << " front = " << front << endl;
  enqueue(222);
  enqueue(333);
  print();
  cout << "rear = " << rear << " front = " << front << endl;
}

