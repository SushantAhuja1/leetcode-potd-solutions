class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        unordered_map<int,int>mp;
        mp[0]=1;
        int sum=0,cnt=0;
        for(int i=0;i<n;i++) {
            sum+=nums[i];
            int req=sum-goal;
            if(mp.count(req)) {
                cnt+=mp[req];
            }
            mp[sum]++;
        }
        return cnt;
    }
};