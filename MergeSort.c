#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100000
void merge(int *A,int num,int p,int q,int r);
void merge_sort(int *A,int num,int p,int r);
void reverse(int *A,int num);
int main()
{
    clock_t start_t,end_t;
    float total;
    time_t t;
    int i,n;
    int a[MAX];
    printf("Enter an integer: ");
    scanf("%d",& n);
    srand((unsigned)time(&t));
    for(i=1;i<=n;i++)
    {
        a[i]=rand()%50;
    }
    printf("\n");
    start_t=clock();
    merge_sort(a,n,1,n);
    end_t=clock();
    total=(double)(end_t-start_t)/100.00;
    printf("Total time for average case: %f",total);
    printf("\n");
    start_t=clock();
    merge_sort(a,n,1,n);
    end_t=clock();
    total=(double)(end_t-start_t)/100.00;
    printf("Total time for best case: %f",total);
    printf("\n");
    reverse(a,n);
    start_t=clock();
    merge_sort(a,n,1,n);
    end_t=clock();
    total=(double)(end_t-start_t)/100.00;
    printf("Total time for worst case: %f",total);

}
void merge(int *A,int num,int p,int q,int r)
{
    int i,j,k;
    int n1=q-p+1;
    int n2=r-q;
    int L[n1+1],R[n2+1];
    for(i=1;i<=n1;i++)
    {
        L[i]=A[p+i-1];
    }
    for(j=1;j<=n2;j++)
    {
        R[j]=A[q+j];
    }
    L[n1+1]=100;
    R[n2+1]=100;
    i=1,j=1;
    for(k=p;k<=r;k++)
    {
        if(L[i]<=R[j])
        {
            A[k]=L[i];
            i=i+1;
        }
        else
        {
            A[k]=R[j];
            j=j+1;
        }
    }

}
void merge_sort(int *A,int num,int p,int r)
{
    int q;
    if(p<r)
    {
         q=(p+r)/2;
        merge_sort(A,num,p,q);
        merge_sort(A,num,q+1,r);
        merge(A,num,p,q,r);
    }

}
void reverse(int *A,int num)
{
    int j,i,key;
    for(j=2;j<=num;j++)
    {
        key=A[j];
        i=j-1;
        while(i>0 && key>A[i])
        {
            A[i+1]=A[i];
            i=i-1;
        }
        A[i+1]=key;
    }

}
