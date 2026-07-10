class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    vector<bool>ans;
    int m;
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
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        parent.resize(n);
        rank.resize(n,1);
        iota(parent.begin(),parent.end(),0);
        m=nums.size();
        int i=0,j=0;
        while(j<n) {
            if(nums[j]-nums[i]<=maxDiff) {
                unite(i,j);
            } 
            while(i<=j && nums[j]-nums[i]>maxDiff) {
                i++;
            }
            unite(i,j);
            j++;
        }
        for(auto &query:queries) {
            int x=query[0],y=query[1];
            if(findParent(x)==findParent(y)) {
                ans.push_back(true);
            } else {
                ans.push_back(false);
            }
        }
        return ans;
    }
};