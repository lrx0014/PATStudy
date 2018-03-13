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
                            MergeSort
***********************************************************************/
class MergeSort {
public:
    int* mergeSort(int* A, int n) {
        // write code here
        int result[n];
        sort_helper(A,0,n-1,result);
        return A;
    }

    void sort_helper(int *A,int left,int right,int *result)
    {
        if(1==right-left)
        {
            if(A[left]>A[right])
            {
                int temp = A[left];
                A[left] = A[right];
                A[right] = temp;
            }
            return;
        }else if(0==right-left){
            return;
        }else{
            sort_helper(A,left,left+(right-left+1)/2,result);
            sort_helper(A,left+(right-left+1)/2+1,right,result);
            merge(A,left,right,result);
            for(int i=left;i<=right;i++)
            {
                A[i] = result[i];
            }
        }
    }

    void merge(int *A,int start,int end,int *result)
    {
        int left_len = (end-start+1)/2 + 1;
        int left_index = start;
        int right_index = start + left_len;
        int cur_index = left_index;
        while(left_index<start+left_len && right_index<end+1)
        {
            if(A[left_index]<=A[right_index])
            {
                result[cur_index++] = A[left_index++];
            }else{
                result[cur_index++] = A[right_index++];
            }
        }
        while(left_index<start+left_len)
        {
            result[cur_index++] = A[left_index++];
        }
        while(right_index<end+1)
        {
            result[cur_index++] = A[right_index++];
        }
    }
};


/***********************************************************************
                            CountingSort
***********************************************************************/
class CountingSort {
public:
    int* countingSort(int* A, int n) {
        // write code here
        count_sort(A,n);
        return A;
    }
    
    void count_sort(int* A,int n)
    {
        int* sorted      = (int*)malloc(sizeof(int)*n);
        int* count_array = (int*)malloc(sizeof(int)*1024);
        for(int i=0;i<1024;i++)
        {
            count_array[i] = 0;
        }
        for(int i=0;i<n;i++)
        {
            count_array[A[i]]++;
        }
        for(int i=1;i<1024;i++)
        {
            count_array[i] += count_array[i-1]; 
        }
        for(int i=n;i>0;i--)
        {
            sorted[count_array[A[i-1]]-1] = A[i-1];
            count_array[A[i-1]]--;
        }
        for(int i=0;i<n;i++)
        {
            A[i] = sorted[i];
        }
        free(count_array);
        free(sorted);
    }
};


/***********************************************************************
                            RadixSort
***********************************************************************/
class RadixSort {
public:
    int* radixSort(int* A, int n) {
        // write code here
        radix_sort(A,n);
        return A;
    }
    
    int maxbit(int* A,int n)
    {
        int max   = 1;
        int level = 10;
        for(int i=0;i<n;i++)
        {
            while(A[i]>level)
            {
                level *= 10;
                ++max;
            }
        }
        return max;
    }
    
    void radix_sort(int* A,int n)
    {
        int max = maxbit(A,n);
        int sorted[n];
        int bucket[10];
        int cur = 1;
        for(int i=1;i<=max;i++)
        {
            for(int j=0;j<10;j++)
            {
                bucket[j] = 0;
            }
            for(int j=0;j<n;j++)
            {
                int k = (A[j]/cur)%10;
                bucket[k]++;
            }
            for(int j=1;j<10;j++)
            {
                bucket[j] += bucket[j-1];
            }
            for(int j=n-1;j>=0;j--)
            {
                int k = (A[j]/cur)%10;
                sorted[bucket[k]-1] = A[j];
                bucket[k]--;
            }
            for(int j=0;j<n;j++)
            {
                A[j] = sorted[j];
            }
            cur *= 10;
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
