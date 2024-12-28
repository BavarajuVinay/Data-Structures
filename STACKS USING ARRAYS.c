// STACKS USING ARRAYS 
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
int stack[SIZE];
int top=-1;
int item;
void push();
void pop();
void peep();
void display();
void main()
{
    int ch;
    while(1)
    {
        printf("\n1.push\n2.pop\n3.peep\n4.display\n");
        printf("Enter the choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
           case 1:push();
           break;
           case 2:pop();
           break;
           case 3:peep();
           break;
           case 4:display();
           break;
           default:exit(1);
           break;
        }
    }
}
void push()
{
    if(top==SIZE-1)
    {
        printf("stack is overflow");
    }
    else
    {
        top++;
        printf("Enter the item: ");
        scanf("%d",&item);
        stack[top]=item;
    }
}
void pop()
{
    if(top==-1)
    {
        printf("Stack is underflow");
    }
    else
    {
        printf("The deleted item is %d",stack[top]);
        top--;
    }
}
void peep()
{
    if(top==-1)
    {
        printf("Stack is underflow");
    }
    else
    {
        printf("The top of the stack is %d",stack[top]);
    }
}
void display()
{
    int i;
    if(top==-1)
    {
        printf("stack is underflow");
    }
    else
    {
        for(i=top;i>=0;i--)
        {
            printf("%d\n",stack[i]);
        }
    }
}





