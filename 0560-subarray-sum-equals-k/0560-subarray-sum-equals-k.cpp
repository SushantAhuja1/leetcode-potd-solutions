class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        mp[0]=1;
        int ans=0;
        int currSum=0;
        for(int i=0;i<n;i++) {
            currSum+=nums[i];
            int requiredSum=currSum-k;
            if(mp.count(requiredSum)) {
                ans+=mp[requiredSum];
            }
            mp[currSum]++;
        }
        return ans;
    }
};