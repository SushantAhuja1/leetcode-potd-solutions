class Solution {
public:
    int n;
    bool isTrionic(vector<int>& nums) {
        n=nums.size();
        int cntPeaksValleys=0;
        int PeakIndex=-1,ValleyIndex=-1;
        for(int i=1;i<n-1;i++) {
            if(nums[i]>nums[i-1] && nums[i]>nums[i+1]) {
                PeakIndex=i;
                break;
            }
        }
        for(int i=1;i<n-1;i++) {
            if(nums[i]<nums[i-1] && nums[i]<nums[i+1]) {
                ValleyIndex=i;
                break;
            }
        }
        if(ValleyIndex<PeakIndex) return false;
        for(int i=0;i<n-1;i++) {
            if(nums[i]==nums[i+1]) return false;
        }
        for(int i=1;i<n-1;i++) {
            if((nums[i]>nums[i-1] && nums[i]>nums[i+1]) || (nums[i]<nums[i-1] && nums[i]<nums[i+1])) {
                cntPeaksValleys++;
            }
        }
        return cntPeaksValleys==2;
    }
};