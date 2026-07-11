class DSU {
    vector<int>parent;
    vector<int>rank;
public: 
    DSU(int n) {
        parent.resize(n);
        rank.resize(n,1);
        iota(parent.begin(),parent.end(),0);
    }
    int findParent(int x) {
        if(x==parent[x]) return x;
        return parent[x]=findParent(parent[x]);
    }
    void unite(int x, int y) {
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
};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU alice(n);
        DSU bob(n);
        int aliceComponents=n;
        int bobComponents=n;
        int edgesCount=0;
        for(auto &edge:edges) {
            int type=edge[0],u=edge[1],v=edge[2];
            u--;
            v--;
            if(type==3) {
                int pu=alice.findParent(u);
                int pv=alice.findParent(v);
                if(pu==pv) continue;
                alice.unite(u,v);
                bob.unite(u,v);
                aliceComponents--;
                bobComponents--;
                edgesCount++;
            }
        }
        for(auto &edge:edges) {
            int type=edge[0],u=edge[1],v=edge[2];
            u--;
            v--;
            if(type==3) continue;
            else {
                if(type==1) {
                    int pu=alice.findParent(u);
                    int pv=alice.findParent(v);
                    if(pu==pv) continue;
                    aliceComponents--;
                    alice.unite(u,v);
                } else {
                    int pu=bob.findParent(u);
                    int pv=bob.findParent(v);
                    if(pu==pv) continue;
                    bobComponents--;
                    bob.unite(u,v);
                }
                edgesCount++;
            }
        }
        if(aliceComponents==1 && bobComponents==1) {
            return edges.size()-edgesCount;
        }
        return -1;
    }
};