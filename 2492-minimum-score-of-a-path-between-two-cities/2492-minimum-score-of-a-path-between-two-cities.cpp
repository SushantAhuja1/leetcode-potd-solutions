class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    int findParent(int x) {
        if(x==parent[x]) return x;
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
    int minScore(int n, vector<vector<int>>& roads) {
        parent.resize(n);
        rank.resize(n,1);
        iota(parent.begin(),parent.end(),0);
        for(auto &road:roads) {
            int x=road[0]-1,y=road[1]-1;
            unite(x,y);
        }
        int p=findParent(0);
        // for(int i=0;i<n;i++) {
        //     cout<<"i : "<<i<<" , findParent(i) : "<<findParent(i)<<endl;
        // }
        int ans=1e9;
        for(auto &road:roads) {
            int a=road[0]-1,b=road[1]-1,c=road[2];
            if(findParent(a)==p || findParent(b)==p) {
                ans=min(ans,c);
            }
        }
        // cout<<"ans : "<<ans<<endl;
        return ans;
    }
};