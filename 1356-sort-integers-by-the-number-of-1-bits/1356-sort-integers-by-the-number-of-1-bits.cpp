class Solution {
public:
    static bool cmp(pair<int,int>&a,pair<int,int>&b) {
        if(a.first!=b.first)
            return a.first<b.first;
        return a.second<b.second;
    }
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>>temp;
        for(auto &ele:arr) {
            temp.push_back({__builtin_popcount(ele),ele});
        }
        sort(temp.begin(),temp.end(),cmp);
        vector<int>ans;
        for(auto &ele:temp) {
            ans.push_back(ele.second);
        }
        return ans;
    }
};