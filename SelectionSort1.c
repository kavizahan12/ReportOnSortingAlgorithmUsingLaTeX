#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100000
int main()
{
    time_t t;
    clock_t start_t,end_t;
    float total;
    int a[MAX];
    int i,n;
    printf("Enter an integer: ");
    scanf("%d",& n);
    srand((unsigned)time(&t));
    for(i=1;i<=n;i++)
    {
        a[i]=rand()%50;
    }
    start_t=clock();
    selectionsort(a,n);
    end_t=clock();
    total=(double)(end_t-start_t)/100.00;
    printf("Total time for average case: %f",total);
    printf("\n");
    start_t=clock();
    selectionsort(a,n);
    end_t=clock();
    total=(double)(end_t-start_t)/100.00;
    printf("Total time for best case: %f",total);
    printf("\n");
    selectionsort1(a,n);
    start_t=clock();
    selectionsort(a,n);
    end_t=clock();
    total=(double)(end_t-start_t)/100.00;
    printf("Total time for worst case: %f",total);
}
void selectionsort(int *A,int num)
{
    int i,j,min,temp;
    for(i=1;i<=num;i++)
    {
        min=i;
        for(j=i+1;j<=num;j++)
        {
            if(A[j]<A[min])
            {
                min=j;
            }
        }
        temp=A[i];
        A[i]=A[min];
        A[min]=temp;
    }
}
void selectionsort1(int *A,int num)
{
    int i,j,max,temp;
    for(i=1;i<=num;i++)
    {
        max=i;
        for(j=i+1;j<=num;j++)
        {
            if(A[j]>A[max])
            {
                max=j;
            }
        }
        temp=A[i];
        A[i]=A[max];
        A[max]=temp;
    }
}
