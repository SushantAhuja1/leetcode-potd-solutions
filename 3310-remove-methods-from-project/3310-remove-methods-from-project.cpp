class Solution {
public:
    unordered_map<int,vector<int>>adj;
    unordered_map<int,vector<int>>revAdj;
    vector<bool>visited;
    vector<int>ans;
    unordered_set<int>temp;
    void dfs(int u) {
        visited[u]=true;
        temp.insert(u);
        for(auto &v:adj[u]) {
            if(!visited[v]) {
                dfs(v);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        for(auto &invo:invocations) {
            int u=invo[0],v=invo[1];
            adj[u].push_back(v); // 1->2
            revAdj[v].push_back(u); // 2->1
        }
        visited.resize(n,false);
        dfs(k);
        bool canRemove=true;
        for(auto &t:temp) {
            for(auto &i:revAdj[t]) {
                if(!temp.count(i)) {
                    canRemove=false;
                    break;
                }
            }
        }
        if(canRemove) {
            for(int i=0;i<n;i++) {
                if(temp.count(i)) {
                    continue;
                } else {
                    ans.push_back(i);
                }
            }
        } else {
            ans.resize(n);
            iota(ans.begin(),ans.end(),0);
        }
        return ans;
    }
};