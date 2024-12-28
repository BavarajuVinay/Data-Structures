//SINGLE LINKED LIST
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
void insert_at_specified();
void delete_at_begin();
void delete_at_end();
void delete_at_specified();
void count();
void search();
void sort();
void reverse();
void merge();
void main()
{
    int ch;
    while(1)
    {
        printf("\n1.Create\n2.Display\n3.Insert at begin\n4.Insert at end\n5.Insert at specified\n6.Delete at begin\n7.Delete at end\n8.Delete at specified\n9.Count\n10.Search\n11.Sort\n12.Reverse\n13.Merge\n");
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
            case 5:insert_at_specified();
            break;
            case 6:delete_at_begin();
            break;
            case 7:delete_at_end();
            break;
            case 8:delete_at_specified();
            break;
            case 9:count();
            break;
            case 10:search();
            break;
            case 11:sort();
            break;
            case 12:reverse();
            break;
            case 13:merge();
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
        printf("Enter the value\n");
        scanf("%d",&value);
        new->data=value;
        new->next=NULL;
        if(head==NULL)
        {
            head=new;
            temp=new;
        }
        else
        {
            temp->next=new;
            temp=new;
        }
        printf("Do u want to add one more node to the list\n");
        fflush(stdin);
        scanf("%c",&c);
    }while(c=='y');
}
void display()
{
    temp=head;
    printf("The elements of the list are\n");
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
}
void insert_at_begin()
{
    new=(struct node*)malloc(sizeof(struct node));
    printf("Enter the value\n");
    scanf("%d",&value);
    new->data=value;
    new->next=head;
    head=new;
}
void insert_at_end()
{
    new=(struct node*)malloc(sizeof(struct node));
    printf("Enter the value\n");
    scanf("%d",&value);
    new->data=value;
    new->next=NULL;
    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=new;
}
void insert_at_specified()
{
    int pos;
    new=(struct node*)malloc(sizeof(struct node));
    printf("Enter the value\n");
    scanf("%d",&value);
    printf("Enter the position\n");
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
    printf("The deleted node is : %d",head->data);
    temp=head;
    head=head->next;
    temp->next=NULL;
    free(temp);
}
void delete_at_end()
{
    struct node *d;
    temp=head;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    d=temp->next;
    printf("The deleted node is : %d",d->data);
    temp->next=NULL;
    free(d);
}
void delete_at_specified()
{
    int pos;
    struct node *d;
    printf("Enter the position required to delete\n");
    scanf("%d",&pos);
    temp=head;
    for(i=0;i<pos-1;i++)
    {
        temp=temp->next;
    }
    d=temp->next;
    printf("The deleted node is : %d",d->data);
    temp->next=d->next;
    free(d);
}
void count()
{
    int c=0;
    temp=head;
    while(temp!=NULL)
    {
        c=c+1;
        temp=temp->next;
    }
    printf("The Number of nodes is: %d",c);
}
void search()
{
    int key,flag=0;
    printf("Enter the element to search\n");
    scanf("%d",&key);
    temp=head;
    while(temp!=NULL)
    {
        if(temp->data==key)
        {
            flag=1;
            break;
        }
        temp=temp->next;
    }
    if(flag==1)
    {
        printf("Element %d found in the list",key);
    }
    else
    {
        printf("Element %d not found in the list",key);
    }
}
void sort()
{
    struct node *t1,*t2;
    int t;
    for(t1=head;t1->next!=NULL;t1=t1->next)
    {
        for(t2=head;t2->next!=NULL;t2=t2->next)
        {
            if(t2->data > t2->next->data)
            {
                t=t2->data;
                t2->data=t2->next->data;
                t2->next->data=t;
            }
        }
    }
}
void reverse()
{
    struct node *current,*next;
    struct node *prev=NULL;
    current=head;
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
}
void merge()
{
    struct node *new1,*temp1;
    struct node *head1=NULL;
    char c;
    do
    {
        new=(struct node*)malloc(sizeof(struct node));
        printf("Enter the value\n");
        scanf("%d",&value);
        new1->data=value;
        new1->next=NULL;
        if(head1==NULL)
        {
            head1=new1;
            temp1=new1;
        }
        else
        {
            temp1->next=new1;
            temp1=new1;
        }
        printf("Do u want to add one more node to the list (y/n)?");
        scanf("%c",&c);
    }while(c=='y');
    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=head1;
}