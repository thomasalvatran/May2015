//home/tovantran/Ctest/June4BinarySearchTree.cpp --> 2015-06-06 by ./.tv  owner: tovantran
// Myschoolcode Tree is not linear structure like array or linkedlist it has
// logical start
// and logical end. Only one next element. Tree can traverse left or right not
// straight forward
// Breadth-first all nodes same deepth (level-order)
// Depth-first visit child all nodes in left sub-trees and all childs of right
// sub-trees
//<root><left<<right> preorder D - L - R
//<left><root><right> inorder  L - R - R
//<left><right><root> postorder
#include <iostream>
#include <stdio.h>
using namespace std;

struct Node {
	int data;
	Node *left;
	Node *right;
};

Node *getnewNode(int data) {
	Node *newnode = new Node();
	newnode->data = data;
	newnode->left = newnode->right = NULL;
	return newnode;
}

Node *insertNode(Node **root, int data) {
	if (*root == NULL)
		*root = getnewNode(data);
	else if ((*root)->data >= data)
		(*root)->left = insertNode(&(*root)->left, data);
	else
		(*root)->right = insertNode(&(*root)->right, data);
	return *root;
}

bool searchNode(Node *root, int data) {
	if (root == NULL)
		return false;
	else if (root->data == data)
		return true;
	else if (root->data >= data)
		return searchNode(root->left, data);
	else
		return searchNode(root->right, data);
}

int FindMin(Node *root) {
	if (root == NULL) {
		cout << "Error: Tree is empty\n";
		return -1;
	}
	while (root->left != NULL) {
		root = root->left;
	}
	return root->data; // local root not effect main
}
// In BST right side > root and left side < root
int FindMax(Node *root) {
	if (root == NULL) {
		cout << "Error: Tree is empty\n";
		return -1;
	}
	while (root->right != 0){
		root = root->right;
	}
	return root->data;
}

int FindMinRecur(Node *root) {
	if (root == NULL) {
		cout << "Eror: Tree is empty\n";
		return -1;
	} else if (root->left == NULL)
		return root->data;
	else
		return FindMinRecur(root->left);
}

int findHeight(Node *root) {
	if (root == NULL)
		return -1;
	return max(findHeight(root->left), findHeight(root->right)) + 1;
}

int main() {
	Node *root = NULL;
	insertNode(&root, 5);
	insertNode(&root, 15);
	insertNode(&root, 25);
	insertNode(&root, 55);
	int number;
	cout << "Enter the number\n";
	cin >> number;

	string str = searchNode(root, number) ? "found" : "not found";
	cout << str << endl;
	printf(searchNode(root, 15) ? "found\n" : "not found\n");

	cout << "FindMin Node = " << FindMin(root) << endl;
	cout << "FindMax Node = " << FindMax(root) << endl;
	cout << "FindMinRecursive Node = " << FindMin(root) << endl;
	cout << "FindHeight Node = " << findHeight(root) << endl;
}


