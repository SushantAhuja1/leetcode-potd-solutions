class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>adj;
        vector<int>indegree(colors.size(),0);
        for(auto &edge:edges) {
            int u=edge[0],v=edge[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int>q;
        vector<vector<int>>t(colors.size(),vector<int>(26,0));
        int ans=0;
        for(int i=0;i<colors.size();i++) {
            if(indegree[i]==0) {
                q.push(i);
                t[i][colors[i]-'a']=1;
            }
        }
        int cntNodes=0;
        while(!q.empty()) {
            int u=q.front();
            q.pop();
            cntNodes++;
            ans=max(ans,t[u][colors[u]-'a']);
            for(auto &v:adj[u]) {
                for(int i=0;i<26;i++) {
                    t[v][i]=max(t[v][i],t[u][i]+(colors[v]-'a'==i));
                }
                indegree[v]--;
                if(indegree[v]==0) {
                    q.push(v);
                }
            }
        }
        if(cntNodes!=colors.size()) return -1;
        return ans;
    }
};