class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        int prefixSum=0;
        int suffixSum=accumulate(nums.begin(),nums.end(),0)-nums[0];
        vector<int>ans;
        ans.push_back(abs(prefixSum-suffixSum));
        for(int i=1;i<n;i++) {
            prefixSum+=nums[i-1];
            suffixSum-=nums[i];
            ans.push_back(abs(prefixSum-suffixSum));
        }
        return ans;
    }
};