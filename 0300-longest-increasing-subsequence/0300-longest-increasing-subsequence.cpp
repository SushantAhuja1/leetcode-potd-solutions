class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>arr;
        for(auto &i:nums) {
            if(arr.empty() || i>arr.back()) {
                arr.push_back(i);
            } else {
                int lb=lower_bound(arr.begin(),arr.end(),i)-arr.begin();
                if(lb<arr.size()) {
                    arr[lb]=i;
                }
            }
        }
        return arr.size();
    }
};