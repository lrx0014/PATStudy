#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int maxValue(vector<int> v, vector<int> w, int n, int cap)
{
    vector<vector<int>> dp(n, vector<int>(cap+1,0));
    for(int i=w[0];i<=cap;i++)
    {
        dp[0][i] = v[0];
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=cap;j++)
        {
            dp[i][j] = dp[i-1][j];
            if(j>=w[i])
            {
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
            }
        }
    }
    return dp[n-1][cap];
}

int main()
{
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    cout<<maxValue(arr,arr,3,6)<<endl;
}
