//Insertion sort 
#include <stdio.h>
void main()
{
    int a[20],n,j,i,temp;
    printf("Enter the no of elements: ");
    scanf("%d",&n);
    printf("Enter the array elements: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=1;i<n;i++)
    {
        temp=a[i];
        j=i-1;
        while(temp<a[j] && j>=0)
        {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=temp;
    }
    printf("After sorting the elements are: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}