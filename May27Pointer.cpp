//home/tovantran/Ctest/May27Pointer.cpp --> 2015-05-29 by ./.tv  owner: tovantran
// Thinking in C++ p.499
#include <iostream>
#include <stdio.h>
using namespace std;
int *f(int *x) { // increase via pointer
  (*x)++;
  return x;
}
int &g(int &x) { // reference via reference
  x++;
  return x;
}
void f(int &) {}       // non const
void g(const int &) {} // const

void f(int **x) { (**x)++; }     // increase pointer to pointer
void increment(int *&x) { x++; } // reference pointer

int main() {
  int a = 0;
  f(&a); // increment content via pointer C using direct
  cout << "f&a " << a << endl;

  int *pa = &a; // increment content via pointer C using indirect
  f(pa);
  cout << "f(pa) " << a << endl;

  g(a); // increment content via reference &
  cout << "g(a) " << a << endl;

  //    f(1);    //pass to non const fail
  g(1); // pass to const ok

  int i = 47; // content increment via address of pointer
  int *ip = &i;
  f(&ip);
//  f(&&i); parameter **x
  cout << i << endl;

  int *j = 0; // pointer increment via reference
  increment(j);
  cout << j << endl;

  *pa = 100;  //assign 100 to 'a' using the dereference operator
  cout << "dereference *pa=100 then a = " << a << endl;   //dereference
  int *b = new int(7);
  cout << *b << endl;
  struct node{
      int data;
      node *next;
  };
  node *c = new node;
  c->data = 12; // dereference ->
//  int argc, char *argv[];
  int argc = 2;
  char *argv[2] = {"hello","tom"};
  char *argv1 = "hello Tommy";
  printf("%s\n", argv1);
    for (int i = 0; i < argc ; i++)
//        cout << argv1[i] << endl;
    printf("%s\n", argv[i]);

}
// Output:
// f&a 1
// f(pa) 2
// g(a) 3
// 48
// 0x4
//int *jp = &j;
// invalid of ref of type 'int &' from type 'int *'
//'int *' is a pointer but pointer to address so it is & and
//'int &' with other 'int &' failed

//void increment(int *i) {  (*i)++;}
//cout << "j = " << j << endl;
//increment(jp);  //jp is a pointer point to address so it is &
//j = 48

