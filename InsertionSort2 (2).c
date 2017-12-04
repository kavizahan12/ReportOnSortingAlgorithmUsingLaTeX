#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100000
void insertion_sort(int *p,int num);
int main()
{

    time_t t;
    clock_t start_t,end_t;
    float total;
    int a[MAX];
    int i,j,key,n;
    printf("Please enter an integer: ");
    scanf("%d",& n);
    srand((unsigned)time(&t));
    for(j=1;j<=n;j++)
    {
        a[j]=rand()%50;
    }
    start_t=clock();
    /*for(j=2;j<=n;j++)
    {
        key=a[j];
        i=j-1;
        while(i>0 && a[i]>key)
        {
            a[i+1]=a[i];
            i=i-1;
        }
        a[i+1]=key;

    }*/
    insertion_sort(a,n);
    end_t=clock();
    total=(double)(end_t-start_t)/100.0;
    printf("Total time for average case: %f",total);
    printf("\n");
    start_t=clock();
    /*for(j=2;j<=n;j++)
    {
        key=a[j];
        i=j-1;
        while(i>0 && a[i]>key)
        {
            a[i+1]=a[i];
            i=i-1;
        }
        a[i+1]=key;
        //insertion_sort(a);
    }*/
    insertion_sort(a,n);

    end_t=clock();
    total=(double)(end_t-start_t)/100.0;
    printf("Total time for best case: %f",total);
    printf("\n");
    for(j=2;j<=n;j++)
    {
        key=a[j];
        i=j-1;
        while(i>0 && key>a[i])
        {
            a[i+1]=a[i];
            i=i-1;
        }
        a[i+1]=key;
    }
    start_t=clock();
    /*for(j=2;j<=n;j++)
    {
        key=a[j];
        i=j-1;
        while(i>0 && a[i]>key)
        {
            a[i+1]=a[i];
            i=i-1;
        }
        a[i+1]=key;
        //insertion_sort(a);
    }*/
    insertion_sort(a,n);
    end_t=clock();
    total=(double)(end_t-start_t)/100.0;
    printf("Total time for worst case: %.f",total);
}
void insertion_sort(int *p,int num)
{
    int i,j,key;
    for(j=2;j<=num;j++)
    {
    key=p[j];
    i=j-1;
    while(i>0 && p[i]>key)
    {
        p[i+1]=p[i];
        i=i-1;
    }
    p[i+1]=key;
    }
}
