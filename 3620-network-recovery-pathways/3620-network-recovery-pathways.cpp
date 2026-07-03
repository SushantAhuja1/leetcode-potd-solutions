class Solution {
public:
    #define ll long long
    #define p pair<ll,int>
    int n;
    unordered_map<int,vector<pair<int,int>>>adj;
    bool isPossible(int mid,vector<bool>& online,ll k) {
        priority_queue<p,vector<p>,greater<>>pq;
        pq.push({0,0}); //{dist,node}
        vector<ll>arr(n,1e18);
        arr[0]=0;
        while(!pq.empty()) {
            ll dist=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(dist>arr[node]) continue;
            if(node==n-1) return true; 
            for(auto &nbr:adj[node]) {
                int nbrNode=nbr.first;
                int cost=nbr.second;
                if(cost<mid) continue;
                if(online[nbrNode] && dist+cost<=k && arr[nbrNode]>dist+cost) {
                    arr[nbrNode]=dist+cost;
                    pq.push({dist+cost,nbrNode});
                }
            }
        }
        // cout<<"arr[n-1] : "<<arr[n-1]<<endl;
        // cout<<"ans : "<<ans<<endl;
        return arr[n-1]<=k;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        n=online.size();
        int low=0,high=0;
        for(auto &edge:edges) {
            int u=edge[0],v=edge[1],wt=edge[2];
            adj[u].push_back({v,wt});
            high=max(high,wt);
        }
        int ans=-1;
        while(low<=high) {
            int mid=low+(high-low)/2;
            // cout<<"mid : "<<mid<<endl;
            if(isPossible(mid,online,k)) {
                ans=mid;
                low=mid+1;
            } else {
                high=mid-1;
            }
        }
        return ans;
    }
};