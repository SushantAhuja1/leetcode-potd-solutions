class Solution {
public:
    int m,n;
    int t[501][501][3];
    int solveTab(vector<vector<int>>& coins) {
        for(int i=m-1;i>=0;i--) {
            for(int j=n-1;j>=0;j--) {
                for(int k=0;k<=2;k++) {
                    if(i>=m || j>=n) {
                        t[i][j][k]=-1e9;
                    }
                    else if (i==m-1 && j==n-1) {
                        if (coins[i][j] >= 0) t[i][j][k]=coins[i][j];
                        else {
                            t[i][j][k]=(k > 0) ? 0 : coins[i][j];
                        }
                    }
                    else {
                        int ans=-1e9;
                        int curr=coins[i][j];
                        if(curr>=0) {
                            ans=max(ans,curr+max(t[i+1][j][k],t[i][j+1][k]));
                        } else {
                            int take=curr+max(t[i+1][j][k],t[i][j+1][k]);
                            int neutralize=-1e9;
                            if(k>0)
                                neutralize=max(t[i+1][j][k-1],t[i][j+1][k-1]);
                            ans=max(ans,max(take,neutralize));
                        }
                        t[i][j][k]=ans;
                    }
                }
            }
        }
        return t[0][0][2];
    }
    int solve(vector<vector<int>>& coins,int i,int j,int k) {
        if(i>=m || j>=n) return -1e9;
        if (i==m-1 && j==n-1) {
            if (coins[i][j] >= 0) return coins[i][j];
            if (k > 0) return max(0, coins[i][j]); 
            return coins[i][j];
        }
        if(t[i][j][k]!=-1) return t[i][j][k];
        int ans=-1e9;
        int curr=coins[i][j];
        if(curr>=0) {
            ans=max(ans,curr+max(solve(coins,i+1,j,k),solve(coins,i,j+1,k)));
        } else {
            int take=curr+max(solve(coins,i+1,j,k),solve(coins,i,j+1,k));
            int neutralize=-1e9;
            if(k>0)
                neutralize=max(solve(coins,i+1,j,k-1),solve(coins,i,j+1,k-1));
            ans=max(ans,max(take,neutralize));
        }
        return t[i][j][k]=ans;
    }
    int maximumAmount(vector<vector<int>>& coins) {
        m=coins.size();
        n=coins[0].size();
        int k=2;
        for(int i=0; i<=m; i++)
            for(int j=0; j<=n; j++)
                for(int k=0; k<3; k++)
                    t[i][j][k] = -1e9;
        
        int ans=solveTab(coins);
        return ans;
    }
};

// -7 12 12 13
// -6 19 19 -6
// 9 -2 -10 16
// -4 14 -10 -9