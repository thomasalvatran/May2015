//home/tovantran/Ctest/MayMergeSort.cpp --> 2015-05-19 by ./.tv  owner: tovantran

#include <vector>
#include <iostream>
#include <stdlib.h>
using namespace std;
#define SIZE 4

int rand_int(int i, int j) { return i + rand() % j; }
void print(int a[], int n) {
  for (int i = 0; i < n; i++)
    cout << a[i] << " ";
  cout << endl;
}
void merge(int a[], int l, int m, int r) {
  int n = r -l + 1;
  int t[n];
  int i1 = l;
  int i2 = m + 1;
  int j = 0;
  while (i1 <= m && i2 <= r) {
    if (a[i1] < a[i2]) {
      t[j] = a[i1];
      i1++;
    } else {
      t[j] = a[i2];
      i2++;
    }
    j++;
  }
  while (i1 <= m) {
    t[j] = a[i1];
    i1++;
    j++;
  }
  while (i2 <= r) {
    t[j] = a[i2];
    i2++;
    j++;
  }
  for (j = 0; j < n; j++)
    a[l + j] = t[j];
}

void mergeSort(int a[], int l, int r) {
  if (l >= r)
      return;
  int m = (l + r) / 2;
  mergeSort(a, l, m);
  mergeSort(a, m + 1, r);
  merge(a, l, m, r);
}

int main() {
  int a[] = {2, 0, 1, 5};
  print(a, 4);
  mergeSort(a, 0, 3);
  print(a, 4);
}

