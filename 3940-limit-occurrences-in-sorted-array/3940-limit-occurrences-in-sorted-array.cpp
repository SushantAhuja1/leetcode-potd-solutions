class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        set<int>seen;
        vector<int>ans;
        int n=nums.size();
        for(auto &i:nums) mp[i]++;
        for(int i=0;i<n;i++) {
            int num=nums[i];
            int frq=mp[num];
            int f=min(frq,k);
            if(!seen.count(num)) {
                for(int t=0;t<f;t++) {
                    ans.push_back(num);
                }
                seen.insert(num);
            }
        }
        return ans;
    }
};