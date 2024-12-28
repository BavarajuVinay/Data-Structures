//SLL MIN AND MAX
#include<stdio.h>
#include<stdlib.h>
struct node
{

    int data;
    struct node *next;
    struct node *prev;
}*new,*temp,*head,*tail;
void create();
void max_min();
void main()
{

    printf("1.create\n2.max and min\n");
    while(1)
    {

        int ch;
        printf("enter your choice :");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:create();
            break;
            case 2:max_min();
            break;
            default:exit(1);
            break;
        }
    }
}
void create()
{
    int value;
    char ch;
    do
    {
    new=(struct node*)malloc(sizeof(struct node));
    printf("enter a value :");
    scanf("%d",&value);
    new->prev=NULL;
    new->data=value;
    new->next=NULL;
    if(head==NULL)
    {
      head=new;
      tail=new;
    }
    else
    {

        tail->next=new;
        new->prev=tail;
        tail=new;
    }
    printf("do you want to add one more node(y/n)\n");
    fflush(stdin);
    scanf("%c",&ch);

}while(ch=='y');
}
void max_min()
{
    struct node *i;
    int max,min;
    min=head->data;
    max=head->data;
    temp=head;
    for(i=temp;i->next!=NULL;i=i->next)
    {

        if(i->next->data >max)
        {

            max=i->next->data;
        }
        else if(i->next->data < min)
        {
            min=i->next->data;
        }
    }
    printf("max=%d and min=%d\n",max,min);
}