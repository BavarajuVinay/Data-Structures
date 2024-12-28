// BST 
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
}*root;
struct node *newnode(int value)
{
    struct node *root=(struct node *)malloc(sizeof(struct node));
    root->data=value;
    root->left=NULL;
    root->right=NULL;
    return root;
}
struct node *insertbst(struct node *root,int value)
{
    if(root==NULL)
    {
        root=newnode(value);   
    }
    else if(root->data>value)
    {
        root->left=insertbst(root->left,value);
    }
    else if(root->data<value)
    {
        root->right=insertbst(root->right,value);
    }
    return root;
}
void inorder(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
struct node *maxvalue(struct node *root)
{
    struct node *current=root;
    if(current!=NULL && current->right!=NULL)
    {
        current=current->right;
    }
    return current;
}
struct node *minvalue(struct node *root)
{
    struct node *current=root;
    if(current!=NULL && current->left!=NULL)
    {
        current=current->left;
    }
    return current;
}
struct node *deletenode(struct node *root,int value)
{
    if(root==NULL)
    {
        return root;
    }
    else if(root->data>value)
    {
        root->left=deletenode(root->left,value);
    }
    else if(root->data<value)
    {
        root->right=deletenode(root->right,value);
    }
    else
    {
        if(root->left==NULL)
        {
            struct node *temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            struct node *temp=root->left;
            free(root);
            return temp;
        }
        else if(root->left!=NULL && root->right!=NULL)
        {
            struct node *temp=minvalue(root->right);
            root->data=temp->data;
            root->right=deletenode(root->right,temp->data);
        }
        else
        {
            root=NULL;
        }
    }
}
void main()
{
    root=insertbst(root,65);
    insertbst(root,23);
    insertbst(root,87);
    insertbst(root,123);
    insertbst(root,98);
    insertbst(root,24);
    insertbst(root,36);
    insertbst(root,55);
    insertbst(root,29);
    deletenode(root,98);
    inorder(root);
    struct node *min=minvalue(root);
    struct node *max=maxvalue(root);
    printf("\nMinvalue is %d",min->data);
    printf("\nMaxvalue is %d",max->data);
    
    
}



