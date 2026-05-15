class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size(),l=0,r=n-1,ans=1e9;
        while(l<=r) {
            int m=l+(r-l)/2;
            if(nums[l]<=nums[r]) {
                ans=min(ans,nums[l]);
                break;
            }
            if(nums[l]<=nums[m]) {
                ans=min(nums[l],ans);
                l=m+1;
            }
            if(nums[m]<=nums[r]) {
                ans=min(ans,nums[m]);
                r=m-1;
            }
        }
        return ans;
    }
};