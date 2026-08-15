class Solution {
public:
    int totalXorr=0;
    bool allZeros(vector<int>& nums) {
        for(auto &i:nums) {
            if(i!=0) return false;
        }
        return true;
    }
    int longestSubsequence(vector<int>& nums) {
        if(allZeros(nums)) {
            return 0;
        }
        for(auto &i:nums) {
            totalXorr^=i;
        }
        if(totalXorr!=0) return (int)nums.size();
        return (int)(nums.size())-1;
    }
};