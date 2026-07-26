class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int cntNeg=0;
        for(auto &i:nums) {
            if(i<0) {
                cntNeg++;
            }
        }
        int prod=1;
        int n=nums.size();
        int ans=INT_MIN;
        prod=prod*nums[n-1];
        prod=prod*nums[n-2];
        prod=prod*nums[n-3];
        ans=max(ans,prod);
        prod=1; 
        if(cntNeg>1) {
            prod=prod*nums[0];
            prod=prod*nums[1];
            prod=prod*nums.back();
            ans=max(ans,prod);
        }
        return ans;
    }
};