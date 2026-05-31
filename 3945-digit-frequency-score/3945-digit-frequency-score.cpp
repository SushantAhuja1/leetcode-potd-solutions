class Solution {
public:
    int digitFrequencyScore(int n) {
        string str=to_string(n);
        unordered_map<char,int>mp;
        for(auto &i:str) {
            mp[i]++;
        }
        int ans=0;
        for(auto &i:mp) {
            ans+=i.second*(i.first-'0');
        }
        return ans;
    }
};