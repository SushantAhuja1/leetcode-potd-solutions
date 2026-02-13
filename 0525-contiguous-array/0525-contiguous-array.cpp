class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        int cnt0=0,cnt1=0,maxL=0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++) {
            if(nums[i]==0) cnt0++;
            if(nums[i]==1) cnt1++;
            if(cnt0==cnt1) maxL=max(maxL,cnt1+cnt0);
            int diff=cnt0-cnt1;
            if(mp.find(diff)!=mp.end()) {
                maxL=max(maxL,i-mp[diff]);
            } else {
                mp[diff]=i;
            }
        }
        return maxL;
    }
};