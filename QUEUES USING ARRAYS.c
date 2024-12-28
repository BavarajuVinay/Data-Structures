//QUEUES USING ARRRAYS
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
int queue[SIZE];
int front=-1,rear=-1;
int item;
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
    if(rear==SIZE-1)
    {
        printf("queue is underflow");
    }
    else
    {
        rear++;
        printf("Enter the item: ");
        scanf("%d",&item);
        queue[rear]=item;
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
        printf("queue is underflow");
    }
    else if(front==rear)
    {
        printf("The deleted element is %d",queue[front]);
        front=-1;
        rear=-1;
    }
    else 
    {
        printf("The deleted element is %d",queue[front]);
        front++;
    }
}
void display()
{
    int i;
    if(front==-1 && rear==-1)
    {
        printf("queue is underflow");
    }
    else
    {
        printf("The elements of the queue are: ");
        for(i=front;i<=rear;i++)
        {
            printf("%d\t",queue[i]);
        }
    }
}









