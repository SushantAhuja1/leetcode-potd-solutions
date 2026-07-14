class Solution {
public:
    #define ll long long
    #define mod (int)(1e9+7)
    int n;
    vector<vector<vector<int>>>dp;
    ll solve(vector<int>& nums, int idx, int gcd1, int gcd2) {
        if(idx>=n) {
            if(gcd1==gcd2) return 1;
            return 0;
        }
        if(dp[idx][gcd1][gcd2]!=-1) return dp[idx][gcd1][gcd2];
        ll skipCurr=solve(nums,idx+1,gcd1,gcd2);
        ll seq1Take=solve(nums,idx+1,__gcd(gcd1,nums[idx]),gcd2);
        ll seq2Take=solve(nums,idx+1,gcd1,__gcd(gcd2,nums[idx]));
        return dp[idx][gcd1][gcd2]=(skipCurr%mod+seq1Take%mod+seq2Take%mod)%mod;
    }
    int subsequencePairCount(vector<int>& nums) {
        n=nums.size();
        dp.resize(n,vector<vector<int>>(500,vector<int>(500,-1)));
        ll res=solve(nums,0,0,0);
        return res-1;
    }
};