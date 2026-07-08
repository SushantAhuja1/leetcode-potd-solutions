class Solution {
public:
    #define ll long long
    vector<int>parent;
    vector<int>rank;
    int find(int x) {
        if(x==parent[x]) return x;
        return parent[x]=find(parent[x]);
    }
    void unite(int x,int y) {
        int px=find(x);
        int py=find(y);
        if(px==py) return;
        if(rank[px]<rank[py]) {
            parent[px]=py;
        } else if(rank[py]<rank[px]) {
            parent[py]=px;
        } else {
            parent[py]=px;
            rank[px]++;
        }
    }
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n=vals.size();
        parent.resize(n);
        rank.resize(n,1);
        iota(parent.begin(),parent.end(),0);
        unordered_map<int,vector<int>>adj;
        for(auto &edge:edges) {
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        map<int,vector<int>>val2Nodes;
        for(int i=0;i<n;i++) {
            val2Nodes[vals[i]].push_back(i);
        }
        int result=n;
        vector<bool>is_active(n,false);
        for(auto &it:val2Nodes) {
            vector<int>nodes=it.second;
            for(int &u:nodes) {
                for(int &v:adj[u]) {
                    if(is_active[v]) {
                        unite(u,v);
                    }
                }
                is_active[u]=true;
            }
            vector<int>tumhare_parents;
            for(int &u:nodes) {
                int parent_kon_hai=find(u);
                tumhare_parents.push_back(parent_kon_hai);
            }
            sort(begin(tumhare_parents),end(tumhare_parents));
            int sz=tumhare_parents.size();
            for(int j=0;j<sz;j++) {
                ll cnt=0;
                int curr_parent=tumhare_parents[j];
                while(j<sz && tumhare_parents[j]==curr_parent) {
                    cnt++;
                    j++;
                }
                j--;
                int formula=(cnt*(cnt-1))/2;
                result+=formula;
            }
        }
        return result;
    }
};