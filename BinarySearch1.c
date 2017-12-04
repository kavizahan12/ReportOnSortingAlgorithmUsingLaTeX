#include<stdio.h>
#include<stdlib.h>
#define MAX 100
void quicksort(int *A,int p,int r);
int partition(int *A,int p,int r);
int binary_search(int *A,int num,int key);
int main()
{
   time_t t;
   int a[MAX];
   int n,i,x,location;
   printf("Please Enter an integer: ");
   scanf("%d",& n);
   srand((unsigned)time(&t));
   for(i=1;i<=n;i++)
   {
       a[i]=rand()%50;
   }
   quicksort(a,1,n);
   for(i=1;i<=n;i++)
   {
       printf("%d ",a[i]);
   }
   printf("\n");
   printf("Please enter a number: ");
   scanf("%d", & x);
   location=binary_search(a,n,x);
   printf("The %d is in location %d",x,location);
}
int binary_search(int *A,int num,int key)
{
    int low=1,high=num;
    int mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(key<A[mid])
        {
            high=mid-1;
        }
        else if(key>A[mid])
        {
            low=mid+1;
        }
        else return mid;
    }
    return 0;
}
int partition(int *A,int p,int r)
{
    int i,j,temp,x;
    x=A[r];
    i=p-1;
    for(j=p;j<=r-1;j++)
    {
        if(A[j]<=x)
        {
            i=i+1;
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
        }
    }
    temp=A[i+1];
    A[i+1]=A[r];
    A[r]=temp;
    return i+1;
}
void quicksort(int *A,int p,int r)
{
    int q;
    if(p<r)
    {
        q=partition(A,p,r);
        quicksort(A,p,q-1);
        quicksort(A,q+1,r);
    }
}
