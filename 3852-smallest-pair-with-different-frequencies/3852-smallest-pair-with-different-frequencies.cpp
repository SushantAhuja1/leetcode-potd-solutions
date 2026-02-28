class Solution {
public:
    int n;
    unordered_map<int,int>mp;
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        n=nums.size();
        for(auto &i:nums) mp[i]++;
        int miniX=1e9;
        int miniY=1e9;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(nums[i]<nums[j] && mp[nums[i]]!=mp[nums[j]]) {
                    if(nums[i]<miniX) {
                        miniX=nums[i];
                        miniY=nums[j];
                    } else if(nums[i]==miniX) {
                        miniY=min(miniY,nums[j]);
                    }
                }
            }
        }
        if(miniX==1e9 || miniY==1e9) return {-1,-1};
        return {miniX,miniY};
    }
};