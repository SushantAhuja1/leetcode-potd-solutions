class Solution {
public:
    #define ll long long
    int compareBitonicSums(vector<int>& nums) {
        int n=nums.size();
        int idx=-1;
        for(int i=1;i<n-1;i++) {
            if(nums[i]>nums[i-1] && nums[i]>nums[i+1]) {
                idx=i;
                break;
            }
        }
        vector<ll>pSum(n,0);
        pSum[0]=nums[0];
        for(int i=1;i<n;i++) {
            pSum[i]=pSum[i-1]+1ll*nums[i];
        }
        ll leftSum=pSum[idx];
        ll rightSum=pSum[n-1]-pSum[idx-1];
        if(leftSum>rightSum) return 0;
        else if(rightSum>leftSum) return 1;
        return -1;
    }
};