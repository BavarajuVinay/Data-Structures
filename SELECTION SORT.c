// SELECTION SORT 
#include <stdio.h>
void selection_sort(int [],int);
void main()
{
    int n,a[20],i;
    printf("Enter the no of array elements: ");
    scanf("%d",&n);
    printf("Enter the array elements: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    selection_sort(a,n);
    printf("After sorting the array elements are: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
void selection_sort(int a[],int n)
{
    int i,j,temp,min;
    for(i=0;i<n;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
            {
                min=j;
            }
            else
            {
                temp=a[i];
                a[i]=a[min];
                a[min]=temp;
            }
        }
    }
}









