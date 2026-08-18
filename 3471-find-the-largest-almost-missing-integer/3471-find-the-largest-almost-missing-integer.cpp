class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<=n-k;i++) {
            unordered_set<int>st;
            for(int j=i;j<i+k;j++) {
                st.insert(nums[j]);
            }
            for(auto &i:st) {
                mp[i]++;
            }
        }
        int ans=-1;
        for(auto &i:mp) {
            if(i.second==1) {
                ans=max(ans,i.first);
            }
        }
        return ans;
    }
};

// [3,9,2,1,7] k=3
// {3-1,9-2,2-3,1-2,7-1}