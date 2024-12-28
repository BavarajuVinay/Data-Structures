// Binary Tree Traversal

#include <stdio.h> 
#include <stdlib.h>
struct node
{
    int item;
    struct node *left;
    struct node *right;
};

// Inorder Traversal

void inorder(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d",root->item);
    inorder(root->right);
}

// Preorder Traversal

void preorder(struct node *root)
{
    if(root==NULL)        // checking whether the root is NULL or not 
    {
        return;           // returns if the root is NULL 
    }
    printf("%d",root->item);
    preorder(root->left);
    preorder(root->right);
}

// Postorder Traversal

void postorder(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d",root->item);
}

// Create a New node

struct node *createnode(int value)
{
    struct node *new=malloc(sizeof(struct node));
    new->item=value;
    new->left=NULL;
    new->right=NULL;
    return new;
}

// Insert On Left 

struct node *insertleft(struct node *root,int value)
{
    root->left=createnode(value);
    return root->left; 
}

// Insert On Right 

struct node *insertright(struct node *root,int value)
{
    root->right=createnode(value);
    return root->right;
}

// Main block of the code 

void main()
{
    struct node *root=createnode(1);
    insertleft(root,2);
    insertright(root,3);
    insertleft(root->left,4);
     // Inorder Traversal
     printf("Inorder Traversal\n");
     inorder(root);
     printf("\n");
     
     // Preorder Traversal
     printf("Preorder Traversal\n");
     preorder(root);
     printf("\n");
     
     // Postorder Traversal
     printf("Postorder Traversal\n");
     postorder(root);
     printf("\n");
}







