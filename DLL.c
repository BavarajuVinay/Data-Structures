//DOUBLE LINKED LIST
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next,*prev;
}*temp,*head,*new,*tail;
int value,i;
void create();
void display();
void insert_at_begin();
void insert_at_end();
void insert_at_pos();
void delete_at_begin();
void delete_at_end();
void delete_at_pos();
void reverse();
void main()
{
    int ch;
    while(1)
    {
        printf("\n1.Create\n2.Display\n3.Insert at begin\n4.Insert at end\n5.Insert at pos\n6.delete at begin\n7.delete at end\n8.Delete at position\n9.reverse\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
           case 1:create();
           break;
           case 2:display();
           break;
           case 3:insert_at_begin();
           break;
           case 4:insert_at_end();
           break;
           case 5:insert_at_pos();
           break;
           case 6:delete_at_begin();
           break;
           case 7:delete_at_end();
           break;
           case 8:delete_at_pos();
           break;
           case 9:reverse();
           break;
           default:exit(1);
           break;
        }
    }
}
void create()
{
    char c;
    do
    {
        new=(struct node*)malloc(sizeof(struct node));
        printf("Enter the value: ");
        scanf("%d",&value);
        new->data=value;
        new->next=NULL;
        new->prev=NULL;
        if(head==NULL)
        {
            head=new;
            tail=new;
        }
        else
        {
            tail->next=new;
            tail=new;
        }
        printf("Do u want to add one more node to the list (y/n) :");
        fflush(stdin);
        scanf("%c",&c);
    }while(c=='y');
}
void display()
{
    temp=head;
    while(temp!=NULL)
    {
        printf("%d<->",temp->data);
        temp=temp->next;
    }
}
void insert_at_begin()
{
    new=(struct node *)malloc(sizeof(struct node));
    printf("Enter the value\n");
    scanf("%d",&value);
    new->data=value;
    new->prev=NULL;
    new->next=head;
    head->prev=new;
    head=new;
}
void insert_at_end()
{
    new=(struct node *)malloc(sizeof(struct node));
    printf("Enter the value\n");
    scanf("%d",&value);
    new->data=value;
    new->next=NULL;
    tail->next=new;
    new->prev=tail;
    tail=new;
}
void insert_at_pos()
{
    int pos;
    new=(struct node*)malloc(sizeof(struct node));
    printf("Enter the value\n");
    scanf("%d",&value);
    printf("Enter the positon\n");
    scanf("%d",&pos);
    temp=head;
    for(i=0;i<pos-1;i++)
    {
        temp=temp->next;   
    }
    new->data=value;
    new->next=temp->next;
    temp->next->prev=new;
    temp->next=new;
    new->prev=temp;
}
void delete_at_begin()
{
    temp=head;
    printf("The deleted node is %d\n",head->data);
    head=head->next;
    head->prev=NULL;
    temp->next=NULL;
    free(temp);
}
void delete_at_end()
{
    temp=tail;
    printf("The deleted node is %d\n",tail->data);
    tail=tail->prev;
    tail->next=NULL;
    temp->prev=NULL;
    free(temp);
}
void delete_at_pos()
{
    int pos;
    printf("Enter the position\n");
    scanf("%d",&pos);
    temp=head;
    for(i=0;i<pos-1;i++)
    {
        temp=temp->next;
    }
    printf("The deleted node is %d",temp->next->data);
    temp->next=temp->next->next;
    temp->next->next->prev=temp;
}
void reverse()
{
    temp=tail;
    while(temp!=NULL)
    {
        printf("%d<->",temp->data);
        temp=temp->prev;
    }
}


