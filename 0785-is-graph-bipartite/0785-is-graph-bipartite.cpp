class Solution {
public:
    int n;
    unordered_map<int,vector<int>>adj;
    vector<int>color;
    bool dfs(int node,int c,int parent) {
        color[node]=c;
        for(auto &nbr:adj[node]) {
            if(nbr==parent) continue;
            if(color[nbr]==color[node]) return false;
            if(color[nbr]==-1) {
                if(!dfs(nbr,!c,node)) {
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        n=graph.size();
        color.resize(n,-1);
        for(int i=0;i<n;i++) {
            for(int j=0;j<graph[i].size();j++) {
                adj[i].push_back(graph[i][j]);
                adj[graph[i][j]].push_back(i);
            }
        }
        for(int i=0;i<n;i++) {
            if(color[i]==-1) {
                if(!dfs(i,0,-1)) return false;
            }
        }
        return true;
    }
};