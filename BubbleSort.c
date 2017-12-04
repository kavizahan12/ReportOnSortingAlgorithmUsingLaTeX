#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#define MAX 100000
void bubble_sort(int *A,int num);
int main()
{
    time_t t;
    clock_t start_t,end_t;
    float total;
    int a[MAX];
    int i,n;
    printf("Enter a number: ");
    scanf("%d",& n);
    srand((unsigned)time(&t));
    for(i=1;i<=n;i++)
    {
        a[i]=rand()%50;
    }

    start_t=clock();
    bubble_sort(a,n);
    end_t=clock();
    total=(double)(end_t-start_t)/100.00;
    printf("Total time for average case: %f",total);

    printf("\n");
    start_t=clock();
    bubble_sort(a,n);
    end_t=clock();
    total=(double)(end_t-start_t)/100.00;
    printf("Total time for best case: %f",total);

    printf("\n");
    bubble_sort1(a,n);
    start_t=clock();
    bubble_sort(a,n);
    end_t=clock();
    total=(double)(end_t-start_t)/100.00;
    printf("Total time for worst case: %f",total);

}
void bubble_sort(int *A,int num)
{
    int i,j,temp;
    for(i=1;i<=num;i++)
    {
        for(j=num;j>=i+1;j--)
        {
            if(A[j]<A[j-1])
            {
                temp=A[j];
                A[j]=A[j-1];
                A[j-1]=temp;
            }
        }
    }
}
void bubble_sort1(int *A,int num)
{
    int i,j,temp;
    for(i=1;i<=num;i++)
    {
        for(j=num;j>=i+1;j--)
        {
            if(A[j]>A[j-1])
            {
                temp=A[j];
                A[j]=A[j-1];
                A[j-1]=temp;
            }
        }
    }
}
