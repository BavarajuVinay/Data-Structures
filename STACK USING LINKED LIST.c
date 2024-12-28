//STACKS USING LINKED LISTS
#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int data;
    struct node *next;
}*new,*tos,*temp;
// tos(top of stack)-> points the topmost node
int value;
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
    new=(struct node*)malloc(sizeof(struct node));
    printf("Enter the value: ");
    scanf("%d",&value);
    new->data=value;
    new->next=NULL;
    if(tos==NULL)
    {
        tos=new;
    }
    else
    {
        new->next=tos;
        tos=new;
    }
}
void pop()
{
    if(tos==NULL)
    {
        printf("stack is underflow");
    }
    else
    {
        printf("The deleted node is %d\n",tos->data);
        temp=tos;
        tos=tos->next;
        temp->next=NULL;
        free(temp);
    }
}
void peep()
{
    if(tos==NULL)
    {
        printf("stack is underflow");
    }
    else
    {
        printf("The most element of the stack is %d\n",tos->data);
    }
}
void display()
{
    if(tos==NULL)
    {
        printf("Stack is underflow");
    }
    else
    {
        temp=tos;
        while(temp!=NULL)
        {
            printf("%d\n",temp->data);
            temp=temp->next;
        }
    }
}

























