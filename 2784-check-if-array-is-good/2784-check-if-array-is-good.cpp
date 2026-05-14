class Solution {
public:
    bool isGood(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>arr(maxi+1);
        iota(arr.begin(),arr.end(),1);
        arr.back()=maxi;
        sort(nums.begin(),nums.end());
        if(arr.size()!=nums.size()) return false;
        for(int i=0;i<n;i++) {
            if(nums[i]!=arr[i]) {
                return false;
            }
        }
        return true;
    }
};