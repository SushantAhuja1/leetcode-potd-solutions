class Solution {
public:
    #define ll long long
    int n;
    unordered_map<int,int>mp;
    ll sum=0;
    ll ans=0;
    long long maxSum(vector<int>& nums, int m, int k) {
        n=nums.size();
        for(int i=0;i<k;i++) {
            mp[nums[i]]++;
            sum+=nums[i];
        }
        if(mp.size()>=m) {
            ans=max(ans,sum);
        }
        for(int i=k;i<n;i++) {
            mp[nums[i]]++;
            mp[nums[i-k]]--;
            sum+=nums[i];
            sum-=nums[i-k];
            if(mp[nums[i-k]]==0) {
                mp.erase(nums[i-k]);
            }
            if(mp.size()>=m) {
                ans=max(ans,sum);
            }   
        }
        return ans;
    }
};