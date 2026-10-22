class Solution {
public:
    #define ll long long
    #define mod (int)(1e9+7)
    int dp[5001][1001];
    int solve(int currPos, int endPos, int k) {
        if(k==0) {
            if(currPos==endPos) {
                return 1;
            }
            return 0;
        }
        if(dp[currPos+1000][k]!=-1) return dp[currPos+1000][k];
        ll ans=0;
        ans=(ans%mod+solve(currPos-1,endPos,k-1)%mod)%mod;
        ans=(ans%mod+solve(currPos+1,endPos,k-1)%mod)%mod;
        return dp[currPos+1000][k]=ans;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(startPos,endPos,k);
    }
};