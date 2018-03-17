/// 求需要排序的最短子数组

#include <vector>

using namespace std;

class Subsequence {
public:
    int shortestSubsequence(vector<int> A, int n) {
        // write code here
        int max = A[0];
        int min = A[n-1];
        int left = 0;
        int right = n-1;
        for(int i=1;i<n;i++)
        {
            if(A[i]>=max)
            {
                max = A[i];
            }else{
                left = i;
            }
        }
        for(int j=n-2;j>-1;j--)
        {
            if(A[j]<=min)
            {
                min = A[j];
            }else{
                right = j;
            }
        }
        if(left==0 || right==n-1)
        {
            return 0;
        }
        return left-right+1;
    }
};