// myschoolcode
#include <stdlib.h>
#include <iostream>
using namespace std;

#define SIZE 11
int rear = 0, front = 0;
int a[SIZE];
bool isFull() { return ((rear + 1) % SIZE == front); }
bool isEmpty() { return (rear == front); }
void enqueue(int i) {
  if (isFull()) {
    cout << "full for " << i << endl;
    return;
  }
  rear = (rear + 1) % SIZE;
  a[rear] = i;
}
void dequeue() {
  if (isEmpty() == true)
    return;
  front = (front + 1) % SIZE;
//  a[front] = -1;
}

void print() {
  // Finding number of elements in queue
  int count = (rear + SIZE - front) % SIZE + 1;
  cout << "Queue : ";
  for (int i = 1; i < count; i++) {
    int index = (front + i) % SIZE;
    // Index of element while travesing circularly from front
    cout << a[index] << " ";
  }
  cout << "\n\n";
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
  enqueue(3);
  dequeue();
  enqueue(4);
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
  enqueue(444);
  print();
  dequeue();
  print();
  cout << "rear = " << rear << " front = " << front << endl;
}

