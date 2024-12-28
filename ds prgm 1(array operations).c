//linked list using arrays
#include <stdio.h>
#include <stdlib.h>
void create();
void display();
void insert_at_begin();
void insert_at_end();
void insert_at_pos();
void delete_at_begin();
void delete_at_end();
void delete_at_pos();
void updation();
void search();
void sort();
void reverse();
void merge();
int i,pos,value,n,a[20];
void main()
{
    int ch;
    while(1)
    {
        printf("\n1.create\n2.display\n3.insert at begin\n4.insert at end\n5.insert at position\n6.delete at begin\n7.delete at end\n8.delete at position\n9.updation\n10.search\n11.sort\n12.reverse\n13.merge\n");
        printf("Enter the choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:create();
            break;
            case 2:display();
            break;
            case 3:insert_at_begin();
            break;
            case 4:insert_at_end();
            break;
            case 5:insert_at_pos();
            break;
            case 6:delete_at_begin();
            break;
            case 7:delete_at_end();
            break;
            case 8:delete_at_pos();
            break;
            case 9:updation();
            break;
            case 10:search();
            break;
            case 11:sort();
            break;
            case 12:reverse();
            break;
            case 13:merge();
            break;
            default:exit(1);
            break;
        }
    }
}
void create()
{
    printf("Enter the number of elements in an arrray: ");
    scanf("%d",&n);
    printf("The array elements are: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}
void display()
{
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
void insert_at_begin()
{
    printf("Enter the number to be inserted: ");
    scanf("%d",&value);
    n++;
    for(i=n;i>1;i--)
    {
        a[i-1]=a[i-2];
    }
    a[0]=value;
}
void insert_at_end()
{
    printf("Enter the value to be inserted: ");
    scanf("%d",&value);
    n++;
    a[n-1]=value;
}
void insert_at_pos()
{
    printf("Enter the value to be inserted: ");
    scanf("%d",&value);
    printf("Enter the position: ");
    scanf("%d",&pos);
    n++;
    for(i=n;i>pos+1;i--)
    {
        a[i-1]=a[i-2];
    }
    a[pos]=value;
}
void delete_at_begin()
{
    printf("The deleted element is %d",a[0]);
    n--;
    for(i=0;i<n;i++)
    {
        a[i]=a[i+1];
    }
}
void delete_at_end()
{
    printf("The deleted element is %d",a[n-1]);
    n--;
}
void delete_at_pos()
{
    n--;
    printf("Enter the position: ");
    scanf("%d",&pos);
    printf("The deleted position is %d",a[pos]);
    for(i=pos;i<n;i++)
    {
        a[i]=a[i+1];
    }
}
void updation()
{
    printf("Enter the value: ");
    scanf("%d",&value);
    printf("Enter the position u want to update: ");
    scanf("%d",&pos);
    a[pos]=value;
}
void search()
{
    int flag=0;
    printf("Enter the value to search: ");
    scanf("%d",&value);
    for(i=0;i<n;i++)
    {
        if(value==a[i])
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
        printf("Element found");
    }
    else
    {
        printf("Element not found");
    }
}
void sort()
{
    int j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    
}
void reverse()
{
    for(i=n-1;i>=0;i--)
    {
        printf("%d ",a[i]);
    }
}
void merge()
{
    int c[20],m,j,k,b[20];
    printf("Enter the no of elements: ");
    scanf("%d",&m);
    printf("The array elements are: ");
    for(j=0;j<m;j++)
    {
        scanf("%d",&b[j]);
    }
    for(i=0,k=0;i<n;i++,k++)
    {
        c[k]=a[i];
    }
    for(j=0;j<m;j++,k++)
    {
        c[k]=b[j];
    }
    printf("The elements after merging are: ");
    for(k=0;k<m+n;k++)
    {
        printf("%d ",c[k]);
    }
}



