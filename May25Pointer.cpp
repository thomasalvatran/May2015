#include <iostream>
#include <stdio.h>
using namespace std;

// void increment1(int *i) {  (*i)++; }
// void increment1(int ***i) {  (**i)++; }
// increment1(&jpp);  // 2 level ** so (**i)++
void increment(int *&i) { *i++;  }
void increment1(int *i) { (*i)++; }
void increment1_1(int *&i) { i++; }
void increment1_2(int *i) { (*i)++; }
// void increment(int *i) { (*i)++; cout << i << }
int main() {

  int *i = (int *)1; // pointer ONLY only work with pointer i++ not (**i)++
  int jj = 1; // 1 level *i so (*i)++  (**i) crashed
  // i = &jj;
  // printf("i = %p\n", i);
  cout << "i = " << i << endl;

  // increment(&i);  //overload with signature
  // cout << "jj = " << jj << endl;
  // printf("i = %p\n", i);
  cout << "i = " << i << endl;
  cout << "-----" << endl;
  int *p = 0;
  int j = 47;
  int *jp = &j; // jp = &j jp is address *jp is pointer
  int **jpp = &jp;
  cout << "j = " << j << endl;
  cout << "p = " << p << endl;
  cout << "jp = " << jp << endl;
//   increment(&jp);  // 2 level ** so (**i)++
  increment1_2(jp); // 2 level ** so (**i)++
//  increment1_2(jp);
  cout << "j = " << j << endl;
  cout << "p = " << p << endl;
  cout << "jp = " << jp << endl;
}
