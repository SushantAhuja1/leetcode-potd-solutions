class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>lessThanPivot;
        for(auto &i:nums) {
            if(i<pivot) {
                lessThanPivot.push_back(i);
            }
        }
        for(auto &i:nums) {
            if(i==pivot) {
                lessThanPivot.push_back(i);
            }
        }
        for(auto &i:nums) {
            if(i>pivot) {
                lessThanPivot.push_back(i);
            }
        }
        return lessThanPivot;
    }
};