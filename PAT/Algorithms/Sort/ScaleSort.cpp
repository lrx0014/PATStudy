/// 小范围排序

#include <vector>

using namespace std;

class ScaleSort {
public:
    vector<int> sortElement(vector<int> A, int n, int k) {
        // write code here
        vector<int> B(k);
        for(int i=0;i<k;i++)
        {
            B[i] = A[i];
        }
        create_heap(B,k);
        for(int i=0;i<n-k;i++)
        {
            A[i] = B[0];
            B[0] = A[i+k];
            shift_heap(B,k,0);
        }
        for(int i=n-k;i<n;i++)
        {
            A[i] = B[0];
            if(i==n-1) break;
            B[0] = B[--k];
            shift_heap(B,k,0);
        }
        return A;
    }
    
    void create_heap(vector<int>& A,int n)
    {
        for(int i=n/2-1;i>=0;i--)
        {
            shift_heap(A,n,i);
        }
    }
    
    void shift_heap(vector<int>& A,int n,int parent)
    {
        int node = 0;
        int flag = 1;
        while(2*parent+1<n && flag)
        {
            if(2*parent+2<n && A[2*parent+2]<A[2*parent+1])
            {
                node = 2*parent + 2;
            }else{
                node = 2*parent + 1;
            }
            if(A[parent]>A[node])
            {
                int temp  = A[parent];
                A[parent] = A[node];
                A[node]   = temp;
                parent = node;
            }else{
                flag = 0;
            }
        }
    }
};