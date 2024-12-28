//BALANCING SYMBOLS OR DELIMETER
#include <stdio.h>
#include <stdlib.h>
char stack[20];
int top=-1;
void push(char);
char pop();
void main()
{
    char expr[20],ch;
    int i;
    printf("Enter the delimeter expression: ");
    fgets(expr,20,stdin);
    for(i=0;expr[i]!='\0';i++)
    {
        ch=expr[i];
        if(ch=='('||ch=='['||ch=='{')
        {
            push(ch);
        }
        else if(ch==')')
        {
            if(top==-1)
            {
                printf("Unbalanced equation");
                exit(1);
            }
            else if((ch=pop())!='(')
            {
                printf("Unbalanced equatation");
                exit(1);
            }
        }
        else if(ch==']')
        {
            if(top==-1)
            {
                printf("Unbalanced equation");
                exit(1);
            }
            else if((ch=pop())!='[')
            {
                printf("Unbalanced equatation");
                exit(1);
            }
        }
        else if(ch=='}')
        {
            if(top==-1)
            {
                printf("Unbalanced equation");
                exit(1);
            }
            else if((ch=pop())!='{')
            {
                printf("Unbalanced equatation");
                exit(1);
            }
        }
    }
    if(top==-1)
    {
        printf("Balanced equation");
    }
    else
    {
        printf("Unbalanaced equation");
    }
}
void push(char c)
{
    top++;
    stack[top]=c;
}
char pop()
{
    return stack[top--];
}