class Solution {
public:
    int m,n;
    vector<pair<int,int>>directions={{-1,0},{1,0},{0,1},{0,-1}};
    bool isValid(int i,int j) {
        return (i>=0 && i<m && j>=0 && j<n);
    }
    bool isCyclePresent(int i,int j,vector<vector<char>>& grid,char ch,vector<vector<bool>>& visited,int parent_i,int parent_j) {
        visited[i][j]=true;
        for(auto &dir:directions) {
            int ni=i+dir.first;
            int nj=j+dir.second;
            if(!isValid(ni,nj) || grid[ni][nj]!=ch) continue;
            else if(!visited[ni][nj]) {
                if(isCyclePresent(ni,nj,grid,ch,visited,i,j)) return true;
            } else if(ni!=parent_i || nj!=parent_j) return true;
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        m=grid.size();
        n=grid[0].size();
        //try-for-every-cell-to-find-a-cycle
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(!visited[i][j]) {
                    bool isCycle=isCyclePresent(i,j,grid,grid[i][j],visited,-1,-1);
                    if(isCycle) return true;
                }
            }
        }
        return false;
    }
};