#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

static int count = 0;
int arr[20];


/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node {
  int data;
  struct node *left;
  struct node *right;
};

int isBSTUtil(struct node *node, int min, int max);

/* Returns true if the given tree is a binary search tree
 (efficient version). */
int isBST(struct node *node) {
  //  return(isBSTUtil(node, INT_MIN, INT_MAX));
  return (isBSTUtil(node, INT_MIN, INT_MAX));
}

/* Returns true if the given tree is a BST and its
   values are >= min and <= max. */
int isBSTUtil(struct node *node, int min, int max) {

  /* an empty tree is BST */
  if (node == NULL)
    return 1;

  /* false if this node violates the min/max constraint */
  //    if (node->data < min || node->data > max)
  //       return 0;

  /* otherwise check the subtrees recursively,
   tightening the min or max constraint */
  return node->data > min && node->data < max &&
         isBSTUtil(node->left, min, node->data) && // Allow only distinct values
         isBSTUtil(node->right, node->data, max);  // Allow only distinct values
}

/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct node *newNode(int data) {
  struct node *node = (struct node *)malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return (node);
}
// Method 2: in-order traversal
bool isBST1(struct node *root) {
  static struct node *prev = NULL;

  // traverse the tree in inorder fashion and keep track of prev node
  if (root) {
    if (!isBST1(root->left))
      return false;

    // Allows only distinct valued nodes
    if (prev != NULL && root->data <= prev->data)
      return false;

    prev = root;
    arr[count++] = root->data;
    return isBST1(root->right);
  }

  return true;
}

/* Driver program to test above functions*/
int main() {
//  struct node *root = newNode(4);
//  root->left = newNode(2);
//  root->right = newNode(5);
//  root->left->left = newNode(1);
//  root->left->right = newNode(3);

//  isBST(root) ? "Is BST\n" : "Not a BST\n";

    struct node *root = newNode('R');
    root->left = newNode('H');
    root->right = newNode('a');
    root->left->left = newNode('C');
    root->left->right = newNode('O');
    root->right->right = newNode('e');
    root->right->right->right = newNode('f');
    root->right->right->left = newNode('b');

  if (isBST(root))
    printf("Is BST\n");
  else
    printf("Not a BST\n");

  printf(isBST1(root) ? "Is BST\n" : "Not a BST\n");
  //  getchar();
  for (int i = 0; i < count; i++)
      printf("%c ", arr[i]);
  printf("\n");
  return 0;
}

