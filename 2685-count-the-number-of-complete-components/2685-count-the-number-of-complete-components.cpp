class Solution {
public: 
    vector<int>parent;
    vector<int>rank;
    unordered_map<int,set<int>>mp1;
    unordered_map<int,int>mp2;
    int findParent(int x) {
        if(x==parent[x]) return parent[x];
        return parent[x]=findParent(parent[x]);
    }
    void unite(int x,int y) {
        int px=findParent(x);
        int py=findParent(y);
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
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n,1);
        iota(parent.begin(),parent.end(),0);
        for(auto &edge:edges) {
            int u=edge[0],v=edge[1];
            unite(u,v);
        }
        for(int i=0;i<n;i++) {
            int u=i;
            int p=findParent(u);
            mp1[p].insert(u);
        }
        int cnt=0;
        for(auto &edge:edges) {
            int u=edge[0];
            int p=findParent(u);
            mp2[p]++;
        }
        for(auto &i:mp1) {
            int p=i.first;
            int nodes=i.second.size();
            int edges=mp2[p];
            
            if(edges == (nodes*(nodes-1))/2) {
                cnt++;
            }
        }
        return cnt;
    }
};