class Solution {
public:
    unordered_set<int>st;
    int longestConsecutive(vector<int>& nums) {
        for(auto &i:nums) {
            st.insert(i);
        }
        int maxLen=0;
        for(auto &i:st) {
            if(!st.count(i-1)) {
                int curr=i;
                int cnt=1;
                while(st.count(curr+1)) {
                    curr++;
                    cnt++;
                }
                maxLen=max(maxLen,cnt);
                cnt=0;
            }
        }
        return maxLen;
    }
};