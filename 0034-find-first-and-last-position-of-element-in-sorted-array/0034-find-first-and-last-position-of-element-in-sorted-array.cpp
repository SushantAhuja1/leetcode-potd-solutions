class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size(),low=0,high=n-1,firstPos=-1,lastPos=-1;
        while(low<=high) {
            int mid=low+(high-low)/2;
            if(nums[mid]==target) {
                firstPos=mid;
                high=mid-1;
            } else if(nums[mid]>target) {
                high=mid-1;
            } else {
                low=mid+1;
            }
        }
        low=0,high=n-1;
        while(low<=high) {
            int mid=low+(high-low)/2;
            if(nums[mid]==target) {
                lastPos=mid;
                low=mid+1;
            } else if(nums[mid]>target) {
                high=mid-1;
            } else {
                low=mid+1;
            }
        }
        return {firstPos,lastPos};
    }
};