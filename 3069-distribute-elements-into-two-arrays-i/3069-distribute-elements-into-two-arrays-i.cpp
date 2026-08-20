class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>arr1,arr2,result;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        for(int i=2;i<n;i++) {
            if(arr1.back()>arr2.back()) {
                arr1.push_back(nums[i]);
            } else {
                arr2.push_back(nums[i]);
            }
        }
        for(auto &i:arr1) {
            result.push_back(i);
        }
        for(auto &i:arr2) {
            result.push_back(i);
        }
        return result;
    }
};