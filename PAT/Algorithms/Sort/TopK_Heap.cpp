#include <stdio.h>
#include <algorithm>

using namespace std;

void heap_adjust(int* A,int n,int parent)
{
    int left  = 2*parent+1;
    int right = 2*parent+2;
    int maxId = parent;
    if(left<n && A[left]>A[maxId])
    {
        maxId = left;
    }
    if(right<n && A[right]>A[maxId])
    {
        maxId = right;
    }
    if(maxId != parent)
    {
        swap(A[maxId],A[parent]);
        heap_adjust(A,n,maxId);
    }
}

void heap_sort(int* A,int n)
{
    for(int i=n/2-1;i>=0;i--)
    {
        heap_adjust(A,n,i);
    }
    for(int i=n-1;i>=1;i--)
    {
        swap(A[0],A[i]);
        heap_adjust(A,i,0);
    }
}

int main()
{
    int arr[] = {5,4,2,7,1,2,5,8};
    int size_arr = sizeof(arr)/sizeof(int);
    int k = 4;
    heap_sort(arr,size_arr);
    for(int i=0;i<k;i++)
    {
        printf("%d ",arr[i]);
    }
}
