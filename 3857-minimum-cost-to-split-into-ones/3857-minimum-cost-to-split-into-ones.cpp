class Solution {
public:
    int dp[501];
    int solve(int n) {
        if(n==1) return 0;
        if(dp[n]!=-1) return dp[n];
        if(n%2==1) return dp[n]=(n-1)+solve(n-1);
        return dp[n]=(n/2)*(n/2)+solve(n/2)+solve(n/2);
    }
    int minCost(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n);
    }
};