class Solution {
public:
    int m,n;
    #define t tuple<int,int,int>
    priority_queue<t>pq;
    vector<vector<int>>visited;
    vector<pair<int,int>>directions={{-1,0},{1,0},{0,1},{0,-1}};
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        m=grid.size();
        n=grid[0].size();
        visited.resize(m,vector<int>(n,0));
        health-=grid[0][0];
        pq.push({health,0,0});
        visited[0][0]=1;
        while(!pq.empty()) {
            auto [h,r,c]=pq.top();
            pq.pop();
            if(h==0) continue;
            if(r==m-1 && c==n-1 && h>0) return 1;
            for(auto &dir:directions) {
                int nr=r+dir.first;
                int nc=c+dir.second;
                if(nr>=0 && nr<m && nc>=0 && nc<n && !visited[nr][nc] && h-grid[nr][nc]>0) {
                    visited[nr][nc]=1;
                    pq.push({h-grid[nr][nc],nr,nc});
                }
            } 
        }
        return 0;
    }
};