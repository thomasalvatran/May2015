//home/tovantran/Ctest/May20LinkedListSortMerge.cpp --> 2015-05-29 by ./.tv  owner: tovantran
// Double Linked List
#include <stdio.h>
#include <iostream>
#include <ctime>
#include <stdlib.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node *prev;
};
struct Node *head, *temp, *ptr, *current, *previous, *next;
int rand_int(int a, int b) { return (a + rand()) % b; }

void swap(Node *first, Node *second) { // swap the data
  int tmpValue = first->data;
  first->data = second->data;
  second->data = tmpValue;
}
void swapNode(Node *&first, Node *&second) { // swap the data
  temp = first;
  first = second;
  second = temp;
}
void printNode() {
  Node *tmp = head;
  cout << "print from head -> next" << endl;
  while (tmp->next != 0) {
    cout << tmp->data << " ";
    tmp = tmp->next;
  }
  cout << tmp->data << endl;
  cout << "print from tail ->prev" << endl;
  while (tmp->prev != 0) {
    cout << tmp->data << " ";
    tmp = tmp->prev;
  }
  cout << tmp->data << endl;
}
void reverseDouble2(struct Node **head_ref) {
  struct Node *temp = NULL, *temp1 = NULL;
  struct Node *current = *head_ref, *previous = 0, *next = 0;
  /* swap next and prev for all nodes of
    doubly linked list */
  while (current != NULL) {
    temp = current->prev;
    current->prev = current->next;
    current->next = temp;
    current = current->prev; // next
  }
  /* Before changing head, check for the cases like empty
     list and list with only one node */
  if (temp != NULL)
    *head_ref = temp->prev;
}

void reverseDoubleRecursive(Node *p) {
  int static n = 0;
  n++;
  if (p->next == NULL) {
    head = p;
    return;
  }
  reverseDoubleRecursive(p->next);
  n--;
  swapNode(p->next->next, p->next->prev);
  if (n == 1) { // last node from stack
    swapNode(p->next, p->prev);
    n = 0; // static need to zero for next time
  }
}
void reverseSingleRecursive(Node *p) {
  if (p->next == NULL) {
    head = p;
    return;
  }
  reverseSingleRecursive(p->next);
  temp = p->next;
  temp->next = p;
  p->next = NULL;
}
void reverseDouble(Node *head_ptr) {
  struct Node *current = head_ptr, *previous = 0, *next = 0;
  while (current != NULL) {
    next = current->next;
    current->next = previous; // double linked list has prev/next
    current->prev = next;
    previous = current;
    current = next;
  }
  head = previous; // head is global
}
void reverseSingle(Node *head_ptr) {
  Node *current = head_ptr, *prev = 0, *next = 0;
  while (current != 0) {
    next = current->next;
    current->next = prev; // single linked list has next only
    prev = current;
    current = next;
  }
  head = prev;
}
Node *insertSingle(Node *head, int data) {
  temp = new Node;
  temp->data = data;
  temp->next = NULL;
  if (head == NULL) {
    temp->next = head;
    head = temp;
  } else {
    Node *tmp = head;
    while (tmp->next != 0)
      tmp = tmp->next;
    tmp->next = temp;
  }
  return head;
}
Node *insertDouble(Node *head, int data) {
  temp = new Node;
  temp->data = data;
  temp->next = NULL;
  temp->prev = NULL;
  if (head == NULL)
    head = temp;
  else {
    Node *tmp = head;
    while (tmp->next != 0)
      tmp = tmp->next;

    tmp->next = temp; // modify prev to point previous
    temp->prev = tmp; // double liskedlist has next, prev.
  }
  return head;
}
void insertDouble(int data, int n) // overload
{
  current = head;
  int count = 0;
  while (current != 0) {
    previous = current->prev;
    current = current->next;
    count++;
    if (count == n - 1) {
      temp = new Node;
      temp->data = data;
      temp->next = current->next;
      temp->prev = current;
      current->next = temp;
      current->next->next->prev = temp;
      break;
    }
  }
}
int main() {

  head = new Node;
  head->data = 0;
  head->next = 0;
  head->prev = 0;

  temp = head;
  Node *tmp = head;

  temp->next = new Node;
  temp = temp->next;
  temp->data = 1;
  temp->prev = tmp;

  tmp = temp;

  temp->next = new Node;
  temp = temp->next;
  temp->data = 2;
  temp->prev = tmp;

  tmp = temp;

  temp->next = new Node;
  temp = temp->next;
  temp->data = 3;
  temp->prev = tmp;
  temp->next = 0;
  printNode();
  cout << "----delete first---" << endl;
  temp = head->next; // save head pointer
  delete head;       // delete head
  head = temp;       // restore head
  head->prev = 0;
  printNode();
  cout << "---insert first---" << endl;
  temp = new Node; // fill up temp node
  temp->data = 30;
  temp->next = head;
  temp->prev = 0;
  head->prev = temp;
  head = temp; // assign head to temp
  printNode();
  cout << "---delete last---" << endl;
  current = head;
  while (current->next != 0) {
    current = current->next;
  }
  temp = current->prev;
  temp->next = 0;
  delete current;
  printNode();
  cout << "---insert last---" << endl;
  current = head;
  while (current->next != 0) {
    current = current->next;
  }
  temp = new Node; // create a Node and filled up
  temp->data = 33;
  temp->next = 0;
  temp->prev = current; // this is for double listed list
  current->next = temp;
  printNode();
  cout << "---insertDouble head---" << endl;
  insertDouble(head, 111);
  printNode();
  cout << "----reverseDouble head ---" << endl;
  reverseDouble(head);
  printNode();
  cout << "---reverseDoubleRecursive---" << endl;
  reverseDoubleRecursive(head);
  printNode();
  cout << "------insert middle----" << endl;
  insertDouble(666, 3);
  insertDouble(668, 5);
  insertDouble(667, 2);
  printNode();
}

