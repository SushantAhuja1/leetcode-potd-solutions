class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto &ele:nums) {
            if(ele%2==0) {
                mp[ele]++;
            }
        }
        for(auto &i:nums) {
            if(i%2==0 && mp[i]==1) return i;
        }
        return -1;
    }
};