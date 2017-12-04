#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100000
int parent(int i);
int left(int i);
int right(int i);
void max_heapify(int *A,int i);
void build_max_heap(int *A,int num);
void heap_sort(int *A,int num);
void min_heapify(int *A,int i);
void build_min_heap(int *A,int num);
void heap_sort1(int *A,int num);
int heap_size;
int main()
{
    time_t t;
    clock_t start_t,end_t;
    float total;
   int a[MAX];
   int i,n;
   printf("Please enter a number: ");
   scanf("%d",& n);
   srand((unsigned)time(&t));
   for(i=1;i<=n;i++)
   {
       a[i]=rand()%50;
   }
   //time for average case.
   start_t=clock();
   heap_sort(a,n);
   end_t=clock();
   total=(double)(end_t-start_t)/100.00;
   printf("Total time for average case: %f",total);
   printf("\n");
   //time for base case.
   start_t=clock();
   heap_sort(a,n);
   end_t=clock();
   total=(double)(end_t-start_t)/100.00;
   printf("Total time for best case: %f",total);
   printf("\n");
   //time for worst case.
   heap_sort1(a,n);
   start_t=clock();
   heap_sort(a,n);
   end_t=clock();
   total=(double)(end_t-start_t)/100.00;
   printf("Total time for worst case: %f",total);


}
int parent(int i)
{
    return i/2;
}
int left(int i)
{
    return 2*i;
}
int right(int i)
{
    return 2*i+1;
}
void max_heapify(int *A,int i)
{
    int l,r,largest,temp;
    l=left(i);
    r=right(i);
    if(l<=heap_size && A[l]>A[i])
    {
        largest=l;
    }
    else
    {
        largest=i;
    }
    if(r<=heap_size&& A[r]>A[largest])
    {
        largest=r;
    }
    if(largest!=i)
    {
        temp=A[i];
        A[i]=A[largest];
        A[largest]=temp;
        max_heapify(A,largest);
    }
}
void build_max_heap(int *A,int num)
{
    int i;
    heap_size=num;
    for(i=num/2;i>=1;i--)
    {
        max_heapify(A,i);
    }
}
void heap_sort(int *A,int num)
{
    int i,temp;
    build_max_heap(A,num);
    for(i=num;i>=2;i--)
    {
       temp=A[1];
       A[1]=A[i];
       A[i]=temp;
       heap_size=heap_size-1;
       max_heapify(A,1);
    }
}
void min_heapify(int *A,int i)
{
    int l,r,smallest,temp;
    l=left(i);
    r=right(i);
    if(l<=heap_size && A[l]<A[i])
    {
        smallest=l;
    }
    else
    {
        smallest=i;
    }
    if(r<=heap_size&& A[r]<A[smallest])
    {
        smallest=r;
    }
    if(smallest!=i)
    {
        temp=A[i];
        A[i]=A[smallest];
        A[smallest]=temp;
        max_heapify(A,smallest);
    }
}
void build_min_heap(int *A,int num)
{
    int i;
    heap_size=num;
    for(i=num/2;i>=1;i--)
    {
        min_heapify(A,i);
    }
}
void heap_sort1(int *A,int num)
{
    int i,temp;
    build_min_heap(A,num);
    for(i=num;i>=2;i--)
    {
       temp=A[1];
       A[1]=A[i];
       A[i]=temp;
       heap_size=heap_size-1;
       min_heapify(A,1);
    }
}
