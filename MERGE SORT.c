// Merge Sort 
#include <stdio.h>
int a[20];
void merge(int [],int,int,int);
void divide(int [],int,int);
void main()
{
    int n,i;
    printf("Enter the size of an array: ");
    scanf("%d",&n);
    printf("Enter the elements in an array:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    divide(a,0,n-1);
    printf("After sorting the array elements are: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
void divide(int a[],int l,int u)
{
    int mid;
    if(l<u)
    {
        mid=(l+u)/2;
        divide(a,l,mid);
        divide(a,mid+1,u);
        merge(a,l,mid,u);
    }
}
void merge(int a[],int l,int mid,int u)
{
    int i=l,j=mid+1,k=l,b[20];
    while(i<=mid && j<=u)
    {
        if(a[i]<a[j])
        {
            b[k++]=a[i++];
        }
        else
        {
            b[k++]=a[j++];
        }
    }
    while(i<=mid)
    {
        b[k++]=a[i++];
    }
    while(j<=u)
    {
        b[k++]=a[j++];
    }
    for(i=l;i<=u;i++)
    {
        a[i]=b[i];
    }
}
