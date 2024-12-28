//INFIX TO POSTFIX EXPRESSION
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
void push(char);
char pop();
int priority(char);
int top=-1;
int stack[20];
void main()
{
    char postfix[50],infix[50],ch;
    int i,j=0;
    printf("Enter the infix expression: ");
    fgets(infix,50,stdin);
    for(i=0;infix[i]!='\0';i++)
    {
        ch=infix[i];
        if(ch=='(')
        {
            push(ch);
        }
        else if(ch==')')
        {
            while(stack[top]!='(' && top!=-1)
            {
                postfix[j]=pop();
                j++;
            }
            pop();
        }
        else if(isalpha(ch)||isdigit(ch))
        {
            postfix[j]=ch;
            j++;
        }
        else 
        {
            while(priority(ch)<=priority(stack[top]) && top!=-1)
            {
                postfix[j]=pop();
                j++;
            }
            push(ch);
        }
    }
    while(top!=-1)
    {
        postfix[j]=pop();
        j++;
    }
    postfix[j]='\0';
    printf("Result is %s",postfix);
}
void push(char ch)
{
    top++;
    stack[top]=ch;
}
char pop()
{
    return stack[top--];
}
int priority(char ch)
{
    if(ch=='(')
    {
        return 0;
    }
    else if(ch=='+'||ch=='-')
    {
        return 1;
    }
    else if(ch=='*'||ch=='/'||ch=='%')
    {
        return 2;
    }
    else if(ch=='^')
    {
        return 3;
    }
}