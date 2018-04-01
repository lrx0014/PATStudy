#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int minCost(string A,int n,string B,int m,int c0,int c1,int c2)
{
    int dp[n+1][m+1];
    for(int i=0;i<=m;i++)
    {
        dp[0][i] = i*c0;
    }
    for(int i=0;i<=n;i++)
    {
        dp[i][0] = i*c1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int _min = INT_MAX;
            _min = min(dp[i-1][j]+c1,dp[i][j-1]+c0);
            if(A[i-1] == B[j-1])
            {
                _min = min(_min,dp[i-1][j-1]);
            }
            else
            {
                _min = min(_min,dp[i-1][j-1]+c2);
            }
            dp[i][j] = _min;
        }
    }
    return dp[n][m];
}

int main()
{
    string A = "abc";
    string B = "adc";
    cout<<minCost(A,3,B,3,5,3,100)<<endl;
}
