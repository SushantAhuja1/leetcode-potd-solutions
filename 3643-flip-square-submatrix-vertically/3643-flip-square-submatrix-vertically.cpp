class Solution {
public:
    int m,n;
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        m=grid.size();
        n=grid[0].size();
        for(int j=y;j<=y+k-1;j++) {
            vector<int>tmp;
            for(int i=x;i<=x+k-1;i++) {
                tmp.push_back(grid[i][j]);
            }
            reverse(tmp.begin(),tmp.end());
            int c=0;
            for(int i=x;i<=x+k-1;i++) {
                grid[i][j]=tmp[c];
                c++;
            }
        }
        return grid;
    }
};