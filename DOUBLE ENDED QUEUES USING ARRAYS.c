//DOUBLE ENDED QUEUES USING ARRAYS
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
int DEqueue[SIZE];
int front=-1,rear=-1;
int value;
void insert_at_rear();
void delete_at_front();
void insert_at_front();
void delete_at_rear();
void display();
void main()
{
    int ch;
    while(1)
    {
        printf("\n1.insert at rear\n2.delete at front\n3.insert at front\n4.delete at rear\n5.display\n");
        printf("Enter the choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:insert_at_rear();
            break;
            case 2:delete_at_front();
            break;
            case 3:insert_at_front();
            break;
            case 4:delete_at_rear();
            break;
            case 5:display();
            break;
            default:exit(1);
            break;
        }
    }
}
void insert_at_rear()
{
    if(rear==SIZE-1)
    {
        printf("DEqueue is full");
    }
    else
    {
        rear++;
        printf("Enter the value: ");
        scanf("%d",&value);
        DEqueue[rear]=value;
    }
    if(front==-1)
    {
        front=0;
    }
}
void delete_at_front()
{
    if(front==-1 && rear==-1)
    {
        printf("DEqueue is empty");
    }
    else if(front==rear)
    {
        printf("The deleted element is %d",DEqueue[front]);
        front=-1;
        rear=-1;
    }
    else
    {
        printf("The deleted element is %d",DEqueue[front]);
        front++;
    }
}
void insert_at_front()
{
    if(front==0)
    {
        printf("DEqueue is full");
    }
    else
    {
        printf("Enter the value: ");
        scanf("%d",&value);
        if(front==-1 && rear==-1)
        {
            front++;
            rear++;
            DEqueue[front]=value;
        }
        else
        {
            front--;
            DEqueue[front]=value;
        }
    }
}
void delete_at_rear()
{
    if(front==-1 && rear==-1)
    {
        printf("Dequeue is empty");
    }
    else if(front==rear)
    {
        printf("THe deleted element is %d",DEqueue[front]);
        front--;
        rear--;
    }
    else
    {
        printf("The deleted element is %d",DEqueue[rear]);
        rear--;
    }
}
void display()
{
    int i;
    if(front==-1 && rear==-1)
    {
        printf("DEqueue is empty");
    }
    else
    {
        for(i=front;i<=rear;i++)
        {
            printf("%d ",DEqueue[i]);
        }
    }
}









