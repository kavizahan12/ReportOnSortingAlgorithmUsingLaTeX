#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100
int binary_search(int *A,int num,int x);
void insertion_sort(int *A,int num);
int main()
{
    time_t t;
    int n,i,key,location;
    int a[MAX];
    printf("Please enter an integer: ");
    scanf("%d", & n);
    srand((unsigned)time(&t));
    for(i=1;i<=n;i++)
    {
        a[i]=rand()%50;
    }
    insertion_sort(a,n);
    for(i=1;i<=n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    printf("Please enter a number: ");
    scanf("%d", & key);
    location=binary_search(a,n,key);
    printf("The %d is in location %d",key,location);
}
int binary_search(int *A,int num,int x)
{
    int low=1,high=num;
    int mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(x<A[mid])
        {
            high=mid-1;
        }
        else if(x>A[mid])
        {
            low=mid+1;
        }
        else  return mid;
    }
    return 0;
}
void insertion_sort(int *A,int num)
{
    int i,j,key;
    for(j=2;j<=num;j++)
    {
    key=A[j];
    i=j-1;
    while(i>0 && A[i]>key)
    {
        A[i+1]=A[i];
        i=i-1;
    }
    A[i+1]=key;
    }
}
