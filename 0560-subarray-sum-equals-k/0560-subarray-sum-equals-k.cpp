class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size(),sum=0,cnt=0;
        unordered_map<int,int>mp;
        mp[0]=1;
        for(int i=0;i<n;i++) {
            sum+=nums[i];
            int req=sum-k;
            if(mp.count(req)) {
                cnt+=mp[req];
            } 
            mp[sum]++;
        }
        return cnt;
    }
};