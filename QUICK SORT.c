// Quick sort 
#include <stdio.h> 
void quick(int [],int,int);
void main()
{
    int i,n,a[20];
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    printf("Enter the array elements:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    quick(a,0,n-1);
    printf("After sorting the array elements are:\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
void quick(int a[],int l,int u)
{
    int i=l,j=u+1,temp,p;
    if(l<u)
    {
        p=a[l];
        do 
        {
            do
            {
                i++;
            }while(p>=a[i]);
            do 
            {
                j--;
            }while(p<a[j]);
            if(i<j)
            {
               temp=a[i];
               a[i]=a[j];
               a[j]=temp;
            } 
        }while(i<=j);
        temp=a[j];
        a[j]=a[l];
        a[l]=temp;
        quick(a,l,j-1);
        quick(a,j+1,u);
    }
}