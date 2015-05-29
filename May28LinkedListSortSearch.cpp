//home/tovantran/Ctest/May28LinkedListSortSearch.cpp --> 2015-05-29 by ./.tv  owner: tovantran

#include <iostream>
#include <stdlib.h>
using namespace std;

class Node {
  int value;
  Node *pNext;
  Node *pPrev;

public:
  friend class LinkedList; // friend of linkedlist
  Node(void) : pNext(NULL) {}
  Node(int val) : value(val), pNext(NULL) {}
  Node(int val, Node *next) : value(val), pNext(next) {}
  int getValue() const;
  Node *getNext() const;
};

Node *Node::getNext() const { return pNext; }
int Node::getValue() const { return value; }

class LinkedList {
  Node *pHead;
  Node *pTail;

public:
  //  friend class Node; // friend of Node
  LinkedList(int val);
  ~LinkedList(void);
  void tailAppend(int val);
  void headAppend(int val);
  Node *search(int val);
  Node *getTail() const;
  Node *getHead() const;
  void printHead();
  void printTail();
  void sort(Node *head);
  void swap(Node *, Node *);
};
void LinkedList::swap(Node *first, Node *second) {
  int tmpValue = first->value;
  first->value = second->value;
  second->value = tmpValue;
}
void LinkedList::printHead() {
  Node *current = pHead;
  cout << "Head: ";
  while (current != pTail) { // compare head & tail
    cout << current << "-> " << current->value << " ";
    current = current->pNext;
  }
  cout << current << "-> " << current->value << " ";
  cout << endl;
}
void LinkedList::printTail() {
  Node *current = pTail;
  cout << "Tail: ";
  while (current != pHead) { // compare head & tail
    cout << current << "-> " << current->value << " ";
    current = current->pPrev;
  }
  cout << current << "-> " << current->value << " ";
  cout << endl;
}
void LinkedList::sort(Node *head) {
  bool isSwapped;
  Node *temp1 = NULL, *temp;
  do {
    isSwapped = false;
    temp = head;
    while (temp->pNext != temp1) { // bubble sort
      if (temp->value > temp->pNext->value) {
        swap(temp, temp->pNext);
        isSwapped = true;
        printHead();
      }
      temp = temp->pNext;
    }
    temp1 = temp; // last one n - 1
  } while (isSwapped);
}

Node *LinkedList::getTail() const { return pTail; }

Node *LinkedList::getHead() const { return pHead; }

LinkedList::LinkedList(int val) {
  pHead = new Node(val);
  pTail = pHead;
}

LinkedList::~LinkedList() {}

void LinkedList::tailAppend(int val) {
  if (pHead == NULL) {
    pTail = pHead = new Node(val);
  } else {
    Node *temp;
    temp = pTail;
    pTail->pNext = new Node(val);
    pTail = pTail->pNext;
    pTail->pPrev = temp;
  }
}

void LinkedList::headAppend(int val) {
  if (pHead == NULL) {
    pTail = pHead = new Node(val);
  } else {
    Node *temp = new Node(val);
    temp->pNext = pHead;
    pHead = temp;
    pHead->pNext->pPrev = pHead;
  }
}

Node *LinkedList::search(int val) {
  Node *pNode = pHead;
  while (pNode != NULL) {
    if (pNode->value == val) {
      return pNode;
    }
    pNode = pNode->pNext;
  }
  return NULL;
}
inline int rand_int(int a, int b) { return (a + rand()) % b; }

int main() {
  srand(time(0));
  LinkedList list(rand_int(1, 100));
  list.tailAppend(rand_int(1, 100));
  list.tailAppend(rand_int(1, 100));
  list.headAppend(0);
  list.tailAppend(1);
  list.printHead();
  int num;
  cout << "Enter the number to search in linkedlist: ";
  cin >> num;
  Node *node = list.search(num);
  if (node != NULL)
    cout << "Result: Found " << num << " at address " << node << endl;
  else
    cout << "Result: Cannot find the node with value " << num << endl;
  cout << "Bubble Sort LinkedList:" << endl;
  list.sort(list.getHead());
  cout << "End Sort:" << endl;
  list.printHead();
  list.printTail();
}

