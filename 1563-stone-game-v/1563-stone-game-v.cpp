class Solution {
public: 
    #define ll long long
    int n;
    vector<ll>pSum;
    vector<vector<ll>>dp;
    ll solve(vector<int>& stoneValue, int i, int j) {
        if(i>=j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        ll ans=0;
        for(int k=i;k<j;k++) {
            //[i...k] is leftSum
            ll leftSum=pSum[k]-(i-1>=0?pSum[i-1]:0);
            //[k+1...j] is rightSum
            ll rightSum=pSum[j]-(k>=0?pSum[k]:0);
            //three cases : 
            //leftSum>rightSum
            //rightSum>leftSum
            //leftSum==rightSum
            if(leftSum>rightSum) {
                ans=max(ans,rightSum+solve(stoneValue,k+1,j));
            } else if(rightSum>leftSum) {
                ans=max(ans,leftSum+solve(stoneValue,i,k));
            } else {
                ans=max(ans,max(leftSum+solve(stoneValue,i,k),rightSum+solve(stoneValue,k+1,j)));
            }
        }
        return dp[i][j]=ans;           
    }
    int stoneGameV(vector<int>& stoneValue) {
        n=stoneValue.size();
        pSum.resize(n,0);
        pSum[0]=stoneValue[0];
        for(int i=1;i<n;i++) {
            pSum[i]=pSum[i-1]+stoneValue[i];
        }
        dp.resize(501,vector<ll>(501,-1));
        return solve(stoneValue,0,n-1);
    }
};