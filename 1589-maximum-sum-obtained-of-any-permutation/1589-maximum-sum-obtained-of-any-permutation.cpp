class Solution {
public:
    #define ll long long
    #define mod (int)(1e9+7)
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n=nums.size();
        vector<int>events(n,0);
        for(auto &req:requests) {
            int start=req[0];
            int end=req[1];
            events[start]+=1;
            if(end+1<n)
                events[end+1]-=1;
        }
        for(int i=1;i<n;i++) {
            events[i]+=events[i-1];
        }
        ll result=0;
        sort(nums.begin(),nums.end());
        sort(events.begin(),events.end());
        for(int i=0;i<n;i++) {
            result=((result%mod)+(1ll*nums[i]*events[i])%mod)%mod;
        }
        return (int)(result);
    }
};