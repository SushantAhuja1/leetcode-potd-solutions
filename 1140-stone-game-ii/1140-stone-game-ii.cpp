class Solution {
public:
    int n;
    vector<int>pSum;
    int t[101][101];
    int solve(int i, int m, vector<int>& piles) {
        if(i>=n) return 0;
        if(t[i][m]!=-1) return t[i][m]; 
        int ans=0;
        int totalRemaining = pSum[n - 1] - (i > 0 ? pSum[i - 1] : 0);
        for (int x = 1; x <= 2 * m && i + x <= n; x++) {
            int val = totalRemaining - solve(i + x, max(m, x), piles);
            ans=max(ans,val);
        }
        return t[i][m]=ans;
    }
    int stoneGameII(vector<int>& piles) {
        n=piles.size();
        pSum.resize(n);
        pSum[0]=piles[0];
        for(int i=1;i<n;i++) {
            pSum[i]=pSum[i-1]+piles[i];
        }
        memset(t,-1,sizeof(t));
        return solve(0,1,piles);
    }
};