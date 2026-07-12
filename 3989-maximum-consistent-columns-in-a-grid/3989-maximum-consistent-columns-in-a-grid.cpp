class Solution {
public:
    int m,n;
    int t[251][252];
    bool isPossible(vector<vector<int>>& grid, int limit, int currCol, int prevCol) {
        if(prevCol==-1) return true;
        for(int row=0;row<m;row++) {
            if(abs(grid[row][currCol]-grid[row][prevCol])>limit) return false;
        }
        return true;
    }
    int solve(vector<vector<int>>& grid, int limit, int currCol, int prevCol) {
        if(currCol>=n) {
            return 0;
        }
        if(t[currCol][prevCol+1]!=-1) return t[currCol][prevCol+1];
        int deleteCurrCol=solve(grid,limit,currCol+1,prevCol);
        int preserveCurrCol=0;
        if(isPossible(grid,limit,currCol,prevCol)) {
            preserveCurrCol=1+solve(grid,limit,currCol+1,currCol);
        }
        return t[currCol][prevCol+1]=max(deleteCurrCol,preserveCurrCol);
    }
    int maxConsistentColumns(vector<vector<int>>& grid, int limit) {
        m=grid.size();
        n=grid[0].size();
        memset(t,-1,sizeof(t));
        int ans=solve(grid,limit,0,-1);
        return max(1,ans);
    }
};


// {1,-1,1}
// {2,2,2}
