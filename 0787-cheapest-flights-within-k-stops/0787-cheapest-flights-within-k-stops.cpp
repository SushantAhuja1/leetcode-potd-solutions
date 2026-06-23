class Solution {
public:
    unordered_map<int,vector<pair<int,int>>>adj;
    #define t tuple<int,int,int>
    priority_queue<t,vector<t>,greater<>>pq;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> cost(n, vector<int>(k + 2, 1e9));
        for(auto &flight:flights) {
            int from=flight[0];
            int to=flight[1];
            int price=flight[2];
            adj[from].push_back({to,price});
        }
        pq.push({0,0,src}); //{k,distance,node}
        cost[src][0]=0;
        while(!pq.empty()) {
            auto [currK,dist,node]=pq.top();
            pq.pop();
            if(currK>k+1) continue;
            for(auto &nbr:adj[node]) {
                int nextNode=nbr.first;
                int wt=nbr.second;
                if(currK+1<=k+1 && cost[nextNode][currK+1]>dist+wt) {
                    cost[nextNode][currK+1]=dist+wt;
                    pq.push({currK+1,cost[nextNode][currK+1],nextNode});
                }
            }
        }
        int ans = 1e9;
        for(int i = 0; i <= k + 1; i++) {
            ans = min(ans, cost[dst][i]);
        }
        return ans == 1e9 ? -1 : ans;
    }
};