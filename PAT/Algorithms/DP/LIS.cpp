class LongestIncreasingSubsequence {
public:
    int getLIS(vector<int> A, int n) {
        // write code here
        int dp[n];
        for(int i=0;i<n;i++)
        {
            dp[i] = 1;
        }
        for(int i=0;i<A.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(A[j]<A[i])
                {
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
        }
        int result = INT_MIN;
        for(int i=0;i<n;i++)
        {
            result = max(result,dp[i]);
        }
        return result;
    }
};
