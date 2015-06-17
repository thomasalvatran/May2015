//class double circulate linkedlist, insert head, insert tail, insert middle, sort, search,
//queue, enqueue, dequeue
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

class Node {
  int value;
  Node *pNext;
  Node *pPrev;

public:
//  static const int snode = 2;
  static int snode;
  friend class LinkedList; // friend of linkedlist
  Node(void) : pNext(NULL) { cout << "ctor obj = "<< snode<< endl;}
  Node(int val) : value(val), pNext(NULL) { cout << "ctor1 obj = "<< snode<< endl; } // non circular ll
  Node(int val, Node *next) : value(val), pNext(next) { snode++; cout << "ctor2 obj = "<< snode<< endl; }
  ~Node(){ snode--; cout << "dtor obj = "<< snode<< endl;}
  int getValue() const;
  Node *getNext() const;
};
Node *Node::getNext() const { return pNext; }
int Node::getValue() const { return value; }

int Node::snode = 0; //static need to define definition

class LinkedList {
  Node *pHead;
  Node *pTail;

public:
  //  friend class Node; // friend of Node
  LinkedList(int);
  ~LinkedList();
  void tailAppend(int);
  void headAppend(int);
  void Enqueue(int);
  void Dequeue();
  void insertDouble(int data, int n);
  Node *search(int val);
  Node *getTail() const;
  Node *getHead() const;
  void printHead();
  void printTail();
  void sort(Node *head);
  void swap(Node *, Node *);
};
void LinkedList::insertDouble(int data, int n){
    Node *current = pHead;
    Node *previous, *temp;
    int count = 0;
    while(current != pTail){
        current = current->pNext;
        previous = current->pPrev;
        count++;
        if (count == n -1){
            temp = new Node;
            temp->value = data;
            temp->pNext = current->pNext;
            temp->pPrev = current;
            current->pNext = temp;
            current->pNext->pNext->pPrev = temp;
            break;
        }
    }
}

void LinkedList::Enqueue(int val){ //enqueue at tail
    tailAppend(val);
}
void LinkedList::Dequeue(){  //dequeue from head
    Node *temp = pHead;
    pHead = temp->pNext;
    temp->pNext->pPrev = NULL;
    delete(temp); // head move to next, delete head
}

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
  Node *temp1 = pTail, *temp;
  do {
    isSwapped = false;
    temp = head;
    while (temp != temp1) { // bubble sort
      if (temp->value > temp->pNext->value) {
        swap(temp, temp->pNext);
        isSwapped = true;
        printHead();
      }
      temp = temp->pNext; // move temp and compare again
    }
    temp1 = temp; // last one n - 1 (last -1)
  } while (isSwapped);
}

Node *LinkedList::getTail() const { return pTail; }

Node *LinkedList::getHead() const { return pHead; }

LinkedList::LinkedList(int val) {
  pHead = new Node(val, pHead);
  pTail = pHead;
}

LinkedList::~LinkedList() {}

void LinkedList::tailAppend(int val) {
  if (pHead == NULL) {
    pTail = pHead = new Node(val);
  } else {
    Node *temp = pTail;
//    pTail->pNext = new Node(val);
    pTail->pNext = new Node(val,pHead); //make circulate linkedlist
    pTail = pTail->pNext;
    pTail->pPrev = temp;
  }
}

void LinkedList::headAppend(int val) {
  if (pHead == NULL) {
    pTail = pHead = new Node(val);
  } else {
//    Node *temp = new Node(val);
    Node *temp = new Node(val,pHead); //make circulate linkedlist
    temp->pNext = pHead;
    pHead = temp;
    pHead->pNext->pPrev = pHead;
    pTail->pNext = pHead;             //circular buffer tail->next = head
  }
}

Node *LinkedList::search(int val) {
  Node *pNode = pHead;
  while (pNode != pTail) {
    if (pNode->value == val) {
      return pNode;
    }
    pNode = pNode->pNext;
  }
  return NULL;
}
bool isListCircular(Node *head, Node *tail){
    Node *fast, *slow;
    slow = head;
    fast = head->getNext()->getNext();
    while (slow != tail)
    {
        if (slow >= fast)
            return true;
        slow = slow->getNext();
        fast = fast->getNext();
        cout << slow << " " << fast << endl;
    }
    return false;
}

inline int rand_int(int a, int b) { return (a + rand()) % b; }

int main() {
  srand(time(0));
  LinkedList list(1);
  list.tailAppend(rand_int(1, 100));
  list.tailAppend(rand_int(1, 100));
  list.tailAppend(rand_int(1, 100));
//  list.tailAppend(rand_int(1, 100));
  list.headAppend(0);
//  list.tailAppend(1);
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
  bool isCir = isListCircular(list.getHead(), list.getTail());
  string msg = isCir ? "It is a circulate linkedlist" : "It is NOT circulate linkedlist";
  cout << msg << endl;
  Node test;
  cout << "Number node = " << test.snode << endl;
  cout << "Dequeue head "<< endl;
  list.Dequeue();
  list.printHead();
  cout << "Insert in the middle at node 3 value 55" << endl;
  list.insertDouble(55, 3);
  list.printHead();
  cout <<"---end program dequeue all to free memory---" << endl;
  for (int i = 0; i < test.snode; i++)
      list.Dequeue();

}
