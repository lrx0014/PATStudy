#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <stdlib.h>

using namespace std;


/***********************************************************************
                            BubbleSort
***********************************************************************/
class BubbleSort {
public:
    int* bubbleSort(int* A, int n) {
        // write code here
        int len = n;
        int temp;
        for(int i=0;i<len-1;i++)
        {
            for(int j=0;j<len-1-i;j++)
            {
                if(A[j]>A[j+1])
                {
                    temp   = A[j];
                    A[j]   = A[j+1];
                    A[j+1] = temp;
                }
            }
        }
        return A;
    }
};



/***********************************************************************
                            SelectionSort
***********************************************************************/
class SelectionSort {
public:
    int* selectionSort(int* A, int n) {
        // write code here
        int len = n;
        int min,min_index;
        for(int i=0;i<len;i++)
        {
            min = A[i];
            min_index = i;
            for(int j=i+1;j<len;j++)
            {
                if(min>A[j])
                {
                    min = A[j];
                    min_index = j;
                }
            }
            if(i != min_index)
            {
                int temp = A[i];
                A[i] = A[min_index];
                A[min_index] = temp;
            }

        }
        return A;
    }
};



/***********************************************************************
                            InsertionSort
***********************************************************************/
class InsertionSort {
public:
    int* insertionSort(int* A, int n) {
        // write code here
        for(int i=1;i<n;i++)
        {
            int temp = A[i];
            int j = i - 1;
            while(j>=0 && A[j]>temp)
            {
                A[j+1] = A[j];
                j--;
            }
            A[j+1] = temp;
        }
        return A;
    }
};



/***********************************************************************
                            QuickSort
***********************************************************************/
class QuickSort {
public:
    int* quickSort(int* A, int n) {
        // write code here
        QSort(A,0,n-1);
        return A;
    }

    void QSort(int *A,int low,int high)
    {
        if(low>=high)
        {
            return;
        }
        int first = low;
        int last = high;
        int pivot = A[first];
        while(first<last)
        {
            while(first<last && A[last]>=pivot)
            {
                --last;
            }
            A[first] = A[last];
            while(first<last && A[first]<=pivot)
            {
                ++first;
            }
            A[last] = A[first];
        }
        A[first] = pivot;
        QSort(A,low,first-1);
        QSort(A,first+1,high);
    }
};



/***********************************************************************
                           HeapSort
***********************************************************************/
class HeapSort {
public:
    int* heapSort(int* A, int n) {
        // write code here
        heap_sort(A,n);
        return A;
    }

    void heap_sort(int *A,int n)
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

    void heap_adjust(int *A,int n,int parent)
    {
        int left = 2*parent + 1;
        int right = 2*parent + 2;
        int maxId = parent;
        if(left<n && A[left]>A[maxId])
        {
            maxId = left;
        }
        if(right<n && A[right]>A[maxId])
        {
            maxId = right;
        }
        if(maxId!=parent)
        {
            swap(A[maxId],A[parent]);
            heap_adjust(A,n,maxId);
        }
    }
};


/***********************************************************************
                            ShellSort
***********************************************************************/
class ShellSort {
public:
    int* shellSort(int* A, int n) {
        // write code here
        shell(A,n);
        return A;
    }

    void shell(int *A,int n)
    {
        int gap,i,j;
        for(gap=n/2;gap>0;gap/=2)
        {
            for(i=gap;i<n;i++)
            {
                for(j=i-gap;j>=0&&A[j]>A[j+gap];j-=gap)
                {
                    int temp = A[j];
                    A[j] = A[j+gap];
                    A[j+gap] = temp;
                }
            }
        }
    }
};


/***********************************************************************
                            Main Function
***********************************************************************/

int main()
{
    //
}
