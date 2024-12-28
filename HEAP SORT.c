// Heap Sort
#include <stdio.h>
void heapify(int [],int,int);
void heapsort(int [],int);
void main()
{
    int a[20],n,i;
    printf("Enter the array size: ");
    scanf("%d",&n);
    printf("Enter the array elements:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    heapsort(a,n);
    printf("After sorting the array elements are:\n");
    for(i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }
}
void heapify(int a[],int n,int i)
{
    int max=i,left=2*i+1,right=2*i+2;
    if(left<n && a[left]>a[max])
    {
        max=left;
    }
    if(right<n && a[right]>a[max])
    {
        max=right;
    }
    while(i!=max)
    {
        int temp=a[i];
            a[i]=a[max];
            a[max]=temp;
            heapify(a,n,max);
    }
}
void heapsort(int a[],int n)
{
    int i;
    for(i=n/2-1;i>=0;i--)
    {
        heapify(a,n,i);
    }
    for(i=n-1;i>0;i--)
    {
        int temp=a[i];
            a[i]=a[0];
            a[0]=temp;
        heapify(a,i,0);
    }
}









