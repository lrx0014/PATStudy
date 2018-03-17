#include <vector>
#include <algorithm>
#include <math>

using namespace std;

class ThreeColor {
public:
    vector<int> sortThreeColor(vector<int> A, int n) {
        // write code here
        int left  = 0;
        int right = n-1;
        int cur = 0;
        while(cur<=right)
        {
            if(A[cur]==0)
            {
                swap(A[cur],A[left++]);
                cur++;
            }else if(A[cur]==2)
            {
                swap(A[cur],A[right--]);
            }else{
                cur++;
            }
        }
        return A;
    }
};