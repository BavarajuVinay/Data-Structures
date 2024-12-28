//CIRCULAR QUEUES 
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
int cqueue[SIZE];
int front=-1,rear=-1;
int value;
void enqueue();
void dequeue();
void display();
void main()
{
    int ch;
    while(1)
    {
        printf("\n1.enqueue\n2.dequeue\n3.display\n");
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
    if((front==0 && rear==SIZE-1) || front==rear+1)
    {
        printf("cqueue is full");
    }
    else
    {
        rear=(rear+1)%SIZE;
        printf("Enter the element: ");
        scanf("%d",&value);
        cqueue[rear]=value;
        if(front==-1)
        {
            front=0;
        }
    }
}
void dequeue()
{
    if(front==-1 && rear==-1)
    {
        printf("cqueue is empty");
    }
    else if(front==rear)
    {
        printf("The deleted element is %d",cqueue[front]);
        front=-1;
        rear=-1;
    }
    else
    {
        printf("The deleted element is %d",cqueue[front]);
        front=(front+1)%SIZE;
    }
}
void display()
{
    int i;
    if(front==-1 && rear==-1)
    {
        printf("cqueue is empty");
    }
    else
    {
        for(i=front;i!=rear;i=(i+1)%SIZE)
        {
            printf("%d ",cqueue[i]);
        }
        printf("%d",cqueue[i]);
    }
}













