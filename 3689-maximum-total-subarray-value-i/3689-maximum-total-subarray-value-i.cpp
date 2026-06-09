class Solution {
public:
    #define ll long long
    long long maxTotalValue(vector<int>& nums, int k) {
        int maxi=*max_element(nums.begin(),nums.end());
        int mini=*min_element(nums.begin(),nums.end());
        return 1ll*k*(maxi-mini);
    }
};