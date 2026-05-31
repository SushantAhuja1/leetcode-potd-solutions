class Solution {
public:
    int n;
    unordered_map<int,int>mp;
    int t[1001][1501][2];
    void preCompute(vector<vector<int>>& items) {
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(i!=j && (items[j][0]%items[i][0]==0)) {
                    mp[i]++;
                }
            }
        }
    }
    int solve(vector<vector<int>>& items, int budget, int i, int cnt) {
        if(i>=n) return 0;
        if(budget==0) return 0;
        if(t[i][budget][cnt]!=-1) return t[i][budget][cnt];
        int skip=solve(items,budget,i+1,0);
        if(t[i][budget][cnt]!=-1) return t[i][budget][cnt];
        int take=0;
        if(items[i][1]<=budget) {
            if(cnt==0) {
                take+=mp[i];
            }
            take+=1+solve(items,budget-items[i][1],i,1);
        }
        return t[i][budget][cnt]=max(take,skip);
    }
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        n=items.size();
        vector<int>freeCopyTaken(n,0);
        preCompute(items);
        int cnt=0;
        memset(t,-1,sizeof(t));
        int ans=solve(items,budget,0,cnt);
        return ans;
    }
};