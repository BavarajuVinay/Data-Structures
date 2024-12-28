//QUEUES USING LINKED LISTS
#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int data;
    struct node *next;
}*new,*temp,*front,*rear;
int value;
void enqueue();
void dequeue();
void display();
void main()
{
    int ch;
    while(1)
    {
        printf("\n1.enqueue\n2.dequeue\n3.dislpay\n");
        printf("Enter the choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:enqueue();
            break;
            case 2:dequeue();
            break;
            case 3:display();
            break;
            default:exit(1);
            break;
        }
    }
}
void enqueue()
{
    new=(struct node*)malloc(sizeof(struct node));
    printf("Enter the value: ");
    scanf("%d",&value);
    new->data=value;
    new->next=NULL;
    if(front==NULL && rear==NULL)
    {
        front=new;
        rear=new;
    }
    else
    {
        rear->next=new;
        rear=new;
    }
}
void dequeue()
{
    if(front==NULL && rear==NULL)
    {
        printf("Queue is empty");
    }
    else
    {
        printf("The deleted node is %d",front->data);
        front=front->next;
    }
}
void display()
{
    if(front==NULL && rear==NULL)
    {
        printf("Queue is empty");
    }
    else
    {
        temp=front;
        while(temp!=NULL)
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }
    }
}