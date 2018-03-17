#include <map>
#include <string>
#include <math>

using namespace std;

class DistinctSubstring {
public:
    int longestSubstring(string A, int n) {
        // write code here
        if(n<=1)
        {
            return n;
        }
        map<char,int> m;
        m[A[0]] = 0;
        int result = 0;
        int pre = 0;
        int lastPos = 0;
        for(int i=1;i<n;i++)
        {
            if(m.count(A[i]) == 1)
            {
                lastPos = m[A[i]];
            }
            else
            {
                lastPos = -1;
            }
            pre = max(pre, lastPos+1);
            result = max(result, i-pre+1);
            m[A[i]] = i;
        }
        return result;
    }
};