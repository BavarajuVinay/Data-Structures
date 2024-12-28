//CIRCULAR LINKED LIST
#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int data;
    struct node *next;
}*head,*temp,*new;
int value,i;
void create();
void display();
void insert_at_begin();
void insert_at_end();
void insert_at_pos();
void delete_at_begin();
void delete_at_end();
void delete_at_pos();
void main()
{
    int ch;
    while(1)
    {
        printf("\n1.Create\n2.Display\n3.Insert at begin\n4.Insert at end\n5.Insert at position\n6.Delete at begin\n7.Delete at end\n8.Delete at position\n");
        printf("Enter the choice\n");
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
        if(head==NULL)
        {
            head=new;
            temp=new;
        }
        else
        {
            temp->next=new;
            temp=new;
            temp->next=head;
        }
        printf("Do u waat to add one more node to the list (y/n): ");
        fflush(stdin);
        scanf("%c",&c);
    }while(c=='y');
}
void display()
{
    temp=head;
    while(temp->next!=head)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("%d",temp->data);
}
void insert_at_begin()
{
    new=(struct node*)malloc(sizeof(struct node));
    printf("Enter the value: ");
    scanf("%d",&value);
    temp=head;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    new->data=value;
    temp->next=new;
    new->next=head;
    head=new;
}
void insert_at_end()
{
    new=(struct node*)malloc(sizeof(struct node));
    printf("Enter the value: ");
    scanf("%d",&value);
    temp=head;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    new->data=value;
    temp->next=new;
    new->next=head;
}
void insert_at_pos()
{
    int pos;
    new=(struct node*)malloc(sizeof(struct node));
    printf("Enter the value: ");
    scanf("%d",&value);
    printf("Enter the postion required to enter: ");
    scanf("%d",&pos);
    temp=head;
    for(i=0;i<pos-1;i++)
    {
        temp=temp->next;
    }
    new->data=value;
    new->next=temp->next;
    temp->next=new;
}
void delete_at_begin()
{
    printf("The deleted node is %d\n",head->data);
    temp=head;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    head=head->next;
    temp->next=head;
}
void delete_at_end()
{
    temp=head;
    while(temp->next->next!=head)
    {
        temp=temp->next;
    }
    printf("The deleted node is %d\n",temp->next->data);
    temp->next=head;
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
    printf("The deleted node is %d\n",temp->next->data);
    temp->next=temp->next->next;
}








