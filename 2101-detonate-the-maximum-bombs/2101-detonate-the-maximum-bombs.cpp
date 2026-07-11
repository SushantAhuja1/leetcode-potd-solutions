class Solution {
public:
    int n;
    unordered_map<int,vector<int>>adj;
    int dfs(int i, vector<vector<int>>& bombs, vector<int>& visited) {
        visited[i]=true;
        int ans=1;
        for(auto &nbr:adj[i]) {
            if(visited[nbr]) continue;
            ans+=dfs(nbr,bombs,visited);
        }
        return ans;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        n=bombs.size();
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(i==j) continue;
                else {
                    //i want to put that in adj if i can detonate j idx bomb
                    long long xi=bombs[i][0],yi=bombs[i][1],ri=bombs[i][2];
                    long long xj=bombs[j][0],yj=bombs[j][1];
                    long long dx=xi-xj;
                    long long dy=yi-yj;
                    if(dx*dx + dy*dy <= ri*ri) {
                        adj[i].push_back(j);
                    }
                }
            }
        }
        int ans=1;
        for(int i=0;i<n;i++) {
            vector<int>visited(n,false);
            int val=dfs(i,bombs,visited);
            ans=max(ans,val);
        }
        return ans;
    }
};