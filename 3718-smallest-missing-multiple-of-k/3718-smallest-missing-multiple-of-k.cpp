class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>st(nums.begin(),nums.end());
        for(int i=1;i<=110;i++) {
            int val=k*i;
            if(!st.count(val)) {
                return val;
            }
        }
        return -1;
    }
};