#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int countWays(vector<int> penny, int n, int aim)
{
    vector<vector<int>> dp(n,vector<int>(aim+1,0));
    for(int i=0;i<n;i++)
    {
        dp[i][0] = 1;
    }

    for(int i=0;i<=aim;i++)
    {
        if(i%penny[0]==0)
        {
            dp[0][i] = 1;
        }
    }

    for(int i=1;i<n;i++)
    {
        for(int j=1;j<aim+1;j++)
        {
            if(j-penny[i]>0)
            {
                dp[i][j] = dp[i-1][j] + dp[i][j-penny[i]];
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n-1][aim];
}

int main()
{
    int p[] = {1,2,4};
    vector<int> penny(begin(p),end(p));
    cout<<countWays(penny,3,3)<<endl;
}
