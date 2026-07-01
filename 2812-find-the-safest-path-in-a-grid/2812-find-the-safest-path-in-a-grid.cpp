class Solution {
public:
    int n;
    vector<pair<int,int>>directions={{-1,0},{1,0},{0,1},{0,-1}};
    vector<vector<int>>score;
    vector<pair<int,int>>thieves;
    bool anyPath(int i,int j,int mid,vector<vector<int>>& visited) {
        if(score[i][j] < mid) return 0;
        if(i>=n || j>=n) return 0;
        if(i==n-1 && j==n-1) return 1;
        visited[i][j]=1;
        for(auto &dir:directions) {
            int ni=i+dir.first;
            int nj=j+dir.second;
            if(ni>=0 && ni<n && nj>=0 && nj<n && score[ni][nj]>=mid && !visited[ni][nj]) {
                if(anyPath(ni,nj,mid,visited)) {
                    return 1;
                }
            }
        }
        return 0;
    }
    bool isPossible(int mid) {
        vector<vector<int>>visited(n,vector<int>(n,0));
        return anyPath(0,0,mid,visited);
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return 0;
        score.resize(n,vector<int>(n,0));
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]==1) {
                    thieves.push_back({i,j});
                }
            }
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]==1) continue;
                else {
                    int mini=1e9;
                    for(auto &thief:thieves) {
                        int curr=abs(thief.first-i)+abs(thief.second-j);
                        mini=min(mini,curr);
                    }
                    score[i][j]=mini;
                }
            }
        }
        // cout<<"Printing score"<<endl;
        // for(int i=0;i<n;i++) {
        //     for(int j=0;j<n;j++) {
        //         cout<<score[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        int low=0,high=2*n,ans=0;
        while(low<=high) {
            int mid=low+(high-low)/2;
            // cout<<"mid : "<<mid<<endl;
            if(isPossible(mid)) {
                // cout<<"YES"<<endl;
                ans=mid;
                low=mid+1;
            } else {
                high=mid-1;
            }
        }
        return ans;
    }
};