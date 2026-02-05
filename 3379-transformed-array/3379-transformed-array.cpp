class Solution {
public:
    int n;
    vector<int> result;
    vector<int> constructTransformedArray(vector<int>& nums) {
        n=nums.size();
        result.resize(n,0);
        for(int i=0;i<n;i++) {
            if(nums[i]==0) {
                result[i]=nums[i];
            } else if(nums[i]>0) {
                result[i]=nums[(i+nums[i])%n];
            } else {
                result[i]=nums[(i-abs(nums[i])%n+n)%n];
            }
        }
        return result;
    }
};