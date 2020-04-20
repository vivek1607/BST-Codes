
#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int height;
};
int height(struct Node *root)
{
    if (root == NULL)
        return 0;
    return root->height;
}
int max(int a, int b)
{
    return (a > b)? a : b;
}
struct Node* newNode(int item)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data=item;
    temp->left=NULL;
    temp->right=NULL;
    temp->height=1;
    return(temp);
}
struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;
    return x;
}
struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
    return y;
}
int getBalance(struct Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}
struct Node* insert(struct Node* node, int item)
{
    if (node == NULL)
        return(newNode(item));

    if (item< node->data)
        node->left  = insert(node->left,item);
    else if (item > node->data)
        node->right = insert(node->right,item);
    else
        return node;
    node->height = 1 + max(height(node->left),height(node->right));
    int balance = getBalance(node);
    if (balance > 1 && item < node->left->data)
        return rightRotate(node);
    if (balance < -1 && item > node->right->data)
        return leftRotate(node);
    if (balance > 1 && item > node->left->data)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && item < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}
void preOrder(struct Node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
int main()
{
  struct Node *root = NULL;
  root = insert(root, 1);
  root = insert(root, 2);
  root = insert(root, 3);
  root = insert(root, 4);
  root = insert(root, 5);
  root = insert(root, 6);
  printf("Preorder traversal is \n");
  preOrder(root);
  return 0;
}

