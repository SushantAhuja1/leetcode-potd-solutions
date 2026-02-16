class Solution {
public:
    vector<int>psum;
    int n;
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        n=nums.size();
        //prefix-sum-calculation
        psum.resize(n,0);
        psum[0]=nums[0];
        for(int i=1;i<n;i++) psum[i]=psum[i-1]+nums[i];
        int ans=0;
        //for each l length sub-array find max sum m length sub-array before and after it
        for(int i=0;i<=n-firstLen;i++) {
            int currentSubarraySum=psum[i+firstLen-1]-(i-1>=0?psum[i-1]:0);
            //m length subarray in left side
            int maxLeftSum=0;
            for(int j=0;j<=i-secondLen;j++) {
                int curr=psum[j+secondLen-1]-(j-1>=0?psum[j-1]:0);
                ans=max(ans,curr+currentSubarraySum);
            }
            //m length subarray in right side
            int maxRightSum=0;
            for(int j=i+firstLen;j<=n-secondLen;j++) {
                int curr=psum[j+secondLen-1]-(j-1>=0?psum[j-1]:0);
                ans=max(ans,curr+currentSubarraySum);
            }
        }
        // cout<<"ans : "<<ans<<endl;
        return ans;
    }
};