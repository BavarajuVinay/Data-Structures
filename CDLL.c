//Circular Double Linked list
#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int data;
    struct node *next,*prev;
}*head,*temp,*new,*tail;
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
        printf("\n1.Create\n2.Display\n3.Insert at begin\n4.Insert at end\n5.Insert at position\n6.Delete at begin\n7.Delete at end\n8.Delete at position\n9.Revrese\n");
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
        new->next=new;
        new->prev=new;
        if(head==NULL)
        {
            head=new;
            tail=new;
        }
        else
        {
            tail->next=new;
            new->prev=tail;
            new->next=head;
            head->prev=new;
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
    while(temp!=tail)
    {
        printf("%d(<->)",temp->data);
        temp=temp->next;
    }
    printf("%d",temp->data);
}
void insert_at_begin()
{
    new=(struct node *)malloc(sizeof(struct node));
    printf("Enter the value\n");
    scanf("%d",&value);
    new->data=value;
    new->prev=tail;
    tail->next=new;
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
    new->next=head;
    head->prev=new;
    tail->next=new;
    new->prev=tail;
    tail=new;
}
void insert_at_pos()
{
    int pos;
    new=(struct node *)malloc(sizeof(struct node));
    printf("Enter the value\n");
    scanf("%d",&value);
    printf("Enter the position :");
    scanf("%d",&pos);
    temp=head;
    for(i=0;i<pos-1;i++)
    {
        temp=temp->next;
    }
    new->data=value;
    new->next=temp->next;
    temp->next->prev=new->next;
    temp->next=new;
    new->prev=temp;
}
void delete_at_begin()
{
    temp=head;
    printf("The deleted node is %d",head->data);
    head=head->next;
    head->prev=tail;
    tail->next=head;
}
void delete_at_end()
{
    printf("The deleted node is %d",tail->data);
    temp=tail;
    tail=tail->prev;
    tail->next=head;
    head->prev=tail;
}
void delete_at_pos()
{
    int pos;
    printf("Enter the postion required to delete: ");
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
    while(temp!=head)
    {
        printf("%d(<->)",temp->data);
        temp=temp->prev;
    }
    printf("%d",temp->data);
}