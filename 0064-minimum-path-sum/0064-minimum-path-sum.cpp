class Solution {
public:
    int m,n;
    int t[201][201];
    int solve(int i,int j,vector<vector<int>>& grid) {
        if(i>=m || j>=n) return 1e9;
        if(t[i][j]!=-1) return t[i][j];
        if(i==m-1 && j==n-1) return grid[i][j];
        return t[i][j]=grid[i][j]+min(solve(i+1,j,grid),solve(i,j+1,grid));
    }
    int minPathSum(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        memset(t,-1,sizeof(t));
        return solve(0,0,grid);
    }
};