// POSTFIX EXPRESSION 
#include <stdio.h>
#include <math.h>
#include <ctype.h>
int stack[20],op1,op2,top=-1;
void push(int);
int pop();
void main()
{
    char postfix[40];
    int res,i;
    printf("Enter the postfix expression :");
    fgets(postfix,20,stdin);
    for(i=0;postfix[i]!='\0';i++)
    {
        if(isdigit(postfix[i]))
        {
            push(postfix[i]-48);
        }
        else
        {
            op2=pop();
            op1=pop();
            switch(postfix[i])
            {
                case '+':push(op1+op2);
                break;
                case '-':push(op1-op2);
                break;
                case '*':push(op1*op2);
                break;
                case '/':push(op1/op2);
                break;
                case '%':push(op1%op2);
                break;
                case '^':res=pow(op1,op2);
                         push(res);
                break;
            }
        }
    }
    printf("The result is %d",pop());
}
void push(int n)
{
    top++;
    stack[top]=n;
}
int pop()
{
    return stack[top--];
}