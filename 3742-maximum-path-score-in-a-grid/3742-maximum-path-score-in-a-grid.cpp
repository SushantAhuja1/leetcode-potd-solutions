class Solution {
public:
    int m,n;
    vector<vector<vector<int>>>t;
    int solve(int i, int j, vector<vector<int>>& grid, int k, int totalCost) {
        //out-of-bounds-or-totalCost-exceeds-k
        if(i>=m || j>=n) return -1e9;
        //current-grid-cell-score
        int score=grid[i][j];
        totalCost+=(score>0);
        if(totalCost>k) return -1e9;
        //reached-last-cell
        if(i==m-1 && j==n-1) {
            return score;
        }
        if(t[i][j][totalCost]!=-1) return t[i][j][totalCost];
        //down-recursive-call
        int down=score+solve(i+1,j,grid,k,totalCost);
        //right-recursive-call
        int right=score+solve(i,j+1,grid,k,totalCost);
        //return-max-of-both-possibilities
        return t[i][j][totalCost]=max(right,down);
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        m=grid.size();
        n=grid[0].size();
        int totalCost=0;
        t.resize(m,vector<vector<int>>(n,vector<int>(k+1,-1)));
        int ans=solve(0,0,grid,k,totalCost);
        return ans<0?-1:ans;
    }
};