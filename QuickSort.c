#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#define MAX 100001
void quicksort(int *A,int p,int r);
int partition(int *A,int p,int r);
void quicksort1(int *A,int p,int r);
int partition1(int *A,int p,int r);
int main()
{
    time_t t;
    clock_t start_t,end_t;
    float total;
    int a[MAX];
    int i,n;
    printf("Enter a number: ");
    scanf("%d",&n);
    srand((unsigned)time(&t));
    for(i=1;i<=n;i++)
    {
        a[i]=rand()%50;
    }
    start_t=clock();
    quicksort(a,1,n);
    end_t=clock();
    total=(double)(end_t-start_t)/100.00;
    printf("Total time for average case: %f",total);
    printf("\n");
    start_t=clock();
    quicksort(a,1,n);
    end_t=clock();
    total=(double)(end_t-start_t)/100.00;
    printf("Total time for best case: %f",total);
    quicksort1(a,1,n);
    printf("\n");
    start_t=clock();
    quicksort(a,1,n);
    end_t=clock();
    total=(double)(end_t-start_t)/100.00;
    printf("Total time for worst case: %f",total);
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
int partition1(int *A,int p,int r)
{
    int i,j,temp,x;
    x=A[r];
     i=p-1;
    for(j=p;j<=r-1;j++)
    {
       if(A[j]>=x)
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
void quicksort1(int *A,int p,int r)
{
    int q;
    if(p<r)
    {
        q=partition1(A,p,r);
        quicksort1(A,p,q-1);
        quicksort1(A,q+1,r);
    }
}


