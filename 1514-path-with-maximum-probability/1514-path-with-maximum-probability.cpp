class Solution {
public:
    #define db double
    int m;
    unordered_map<int,vector<pair<int,db>>>adj;
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        m=succProb.size();
        for(int i=0;i<m;i++) {
            int u=edges[i][0],v=edges[i][1];
            db wt=succProb[i];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        priority_queue<pair<db,int>>pq;
        pq.push({1.0,start_node});
        vector<db>dist(n,0.0);
        dist[start_node]=1.0;
        while(!pq.empty()) {
            auto [prob,node]=pq.top();
            pq.pop();
            for(auto &nbr:adj[node]) {
                int nbrNode=nbr.first;
                db costPrb=nbr.second;
                if(costPrb*prob>dist[nbrNode]) {
                    dist[nbrNode]=costPrb*prob;
                    pq.push({costPrb*prob,nbrNode});
                }
            }
        }
        return dist[end_node];
    }
};