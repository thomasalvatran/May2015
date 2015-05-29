//home/tovantran/Ctest/May16Sort.cpp --> 2015-05-19 by ./.tv  owner: tovantran
//selection, insertion, bubble, merge, quick
#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

int rand_int(int a, int b) { return (a + rand()) % b; }

void print(int a[], int n) {
  for (int i = 0; i < n; i++)
    cout << a[i] << " ";
  cout << endl;
}
void swap(int a[], int i, int j) {
  int temp = a[i];
  a[i] = a[j];
  a[j] = temp;
}
void merge(int a[], int l, int m, int r) {
  int n = r - l + 1;
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
  int m = (r + l) / 2;
  mergeSort(a, l, m);
  mergeSort(a, m + 1, r);
  merge(a, l, m, r);
}
void insertSort(int a[], int n) {
  int i, j, value;
  for (i = 0; i < n; i++) {
    value = a[i];
    for (j = i; j > 0 && value <= a[j - 1]; j--)
      a[j] = a[j - 1];
    a[j] = value;
  }
}
void bubbleSort(int a[], int n) {
  int i, j;
  for (i = 1; i < n; i++)
    for (j = n - 1; j >= i; j--)
      if (a[j] < a[j - 1])
        swap(a, j, j - 1);
}
void selectSort(int a[], int n) {
  int i, j, min;
  for (i = 0; i < n; i++) {
    min = i;
    for (j = i; j < n; j++)
      if (a[j] < a[min])
        min = j;
    swap(a, i, min);
  }
}
int partition1(int a[], int p, int r) {
  int i, j;
  i = p - 1; // pivot p at position l
  for (j = p; j < r; j++) {
    if (a[j] <= a[r]) {
      i++;
      swap(a, i, j);
    }
  }
  swap(a, i + 1, r);
  return (i + 1); // middle
}
int partition(int a[], int l, int r) {
  int p = a[l];
  while (l < r) {
    while (a[l] < p)
      l++;
    while (a[r] > p)
      r--;
    if (l < r)
      swap(a, l, r);
  }
  return r;
}
void quickSort(int a[], int l, int r) {
  int m;
  if (l < r) {
    cout << "partition" << endl;
    //    m = partition1(a, l, r);
    m = partition(a, l, r);
    quickSort(a, l, m - 1);
    quickSort(a, m + 1, r);
  }
}
int main() {
  //  int a[] = {49, 92, 43, 80};
  int a[10];
  srand(time(0));
  for (int i = 0; i < 10; i++)
    a[i] = rand_int(1, 100);
  print(a, 10);
  //  selectSort(a, 4);
  //  insertSort(a, 4);
  //  bubbleSort(a, 4);
  //  mergeSort(a, 0, 3);
  quickSort(a, 0, 9);
  print(a, 10);
}

