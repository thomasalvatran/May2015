//home/tovantran/Ctest/May19LinkedListSort.cpp --> 2015-05-19 by ./.tv  owner: tovantran
//LinkedList using BubbleSort
#include <stdio.h>
#include <iostream>
#include <ctime>
#include <stdlib.h>
using namespace std;

struct Node {
	int data;
	struct Node *next;
};
struct Node *head, *temp;
int rand_int(int a, int b) { return (a + rand()) % b; }

void swapNode(Node *first, Node *second) { // swap the data
	int tmpValue = first->data;
	first->data = second->data;
	second->data = tmpValue;
}
void printNode() {
	Node *tmp = head;
	while (tmp->next != 0) {
		cout << tmp->data << " ";
		tmp = tmp->next;
		// n++;
	}
	cout << tmp->data << endl;
}

int main() {
	int size = 0;
	char a[] = "Testing";
	const char *p = "E";
	a[1] = *p;
	printf("%s\n", a);

	srand(time(0));

	head = new Node;
	head->data = rand_int(1, 10);
	head->next = 0;
	size++;
	temp = head;
	temp->next = new Node;
	temp = temp->next;
	temp->data = rand_int(1, 10);
	size++;
	temp->next = new Node;
	temp = temp->next;
	temp->data = rand_int(1, 10);
	size++;
	temp->next = new Node;
	temp = temp->next;
	temp->data = rand_int(1, 10);
	size++;
	temp->next = new Node;
	temp = temp->next;
	temp->data = rand_int(1, 10);
	size++;
	printNode();

	bool isSwapped;
	Node *temp1 = NULL;
	do {
		isSwapped = false;
		temp = head;
		while (temp->next != temp1) { //bubble sort
			if (temp->data > temp->next->data) {
				swapNode(temp, temp->next);
				isSwapped = true;
				printNode();
			}
			temp = temp->next;
		}
		temp1 = temp;                //last one n - 1
	} while (isSwapped);

	printNode();
}



