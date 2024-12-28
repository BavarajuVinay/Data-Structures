// BUBBLE SORT 
#include <stdio.h>
void bubble_sort(int[],int);
void main()
{
    int n,a[20],i;
    printf("Enter the no of elements of array: ");
    scanf("%d",&n);
    printf("Enter the array elements are: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    bubble_sort(a,n);
    printf("The elements after sorting are: \n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
void bubble_sort(int a[],int n)
{
    int i,j,temp;
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
