#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node* insertd(int data)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->left=0;
    temp->right=0;
    return temp;
};
struct node* create(struct node *root,int data)
{
    if(root==0)
    {
        return insertd(data);
    }
    else
    {
        if(data>root->data)
        {
            root->right=create(root->right,data);
        }
        else if(data<root->data)
        {
            root->left=create(root->left,data);
        }
    }
};
int h(struct node *root)
{
    int l,r;
    if(root==0)
    {
        return 0;
    }
    l=h(root->left);
    r=h(root->right);
    if(l>r)
        return l+1;
    else
        return r+1;
}
void call(struct node *root)
{
    int l,r;
    if(root==0)
    {
        return;
    }
    call(root->left);
    l=h(root->left);
    call(root->right);
    r=h(root->right);
    if((l-r)==1||(l-r)==0||(l-r)==-1)
    {
        printf("%d is a balanced node\n",root->data);
    }
    else if(l-r>1)
        printf("%d is a left unbalanced node\n",root->data);
    else if(l-r<-1)
         printf("%d is a right1 unbalanced node\n",root->data);
}
int main()
{
    struct node *root=0;
    root=create(root,1);
    create(root,2);
    create(root,3);
    create(root,4);
    create(root,5);
    create(root,6);
    call(root);
}

