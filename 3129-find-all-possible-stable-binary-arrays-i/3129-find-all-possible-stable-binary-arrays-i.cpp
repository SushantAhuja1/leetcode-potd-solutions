class Solution {
public:
    #define ll long long
    #define mod (int)(1e9+7)
    int dp[201][201][2];
    int solve(int zero, int one, bool wasPrevOne, int limit) {
        if(zero==0 && one==0) return 1;
        if(dp[zero][one][wasPrevOne]!=-1) return dp[zero][one][wasPrevOne];
        ll result=0;
        if(wasPrevOne) {
            for(int i=1;i<=min(zero,limit);i++) {
                result=(result%mod+solve(zero-i,one,!wasPrevOne,limit)%mod)%mod;
            }
        } else {
            for(int i=1;i<=min(one,limit);i++) {
                result=(result%mod+solve(zero,one-i,!wasPrevOne,limit)%mod)%mod;
            }
        }
        return dp[zero][one][wasPrevOne]=result;
    }
    int numberOfStableArrays(int zero, int one, int limit) {
        memset(dp,-1,sizeof(dp));
        return (solve(zero,one,true,limit)%mod+solve(zero,one,false,limit)%mod)%mod;
    }
};