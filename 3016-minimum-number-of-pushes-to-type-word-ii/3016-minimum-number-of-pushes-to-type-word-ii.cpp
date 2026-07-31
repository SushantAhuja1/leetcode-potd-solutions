class Solution {
public:
    vector<pair<char,int>>vec;
    unordered_map<char,int>mp;
    static bool cmp(pair<char,int>& a, pair<char,int>& b) {
        return a.second>b.second;
    }
    int minimumPushes(string word) {
        for(auto &i:word) {
            mp[i]++;
        }
        for(auto &i:mp) {
            vec.push_back({i.first,i.second});
        }
        sort(vec.begin(),vec.end(),cmp);
        //total nums=8
        int currNumsAvail=8;
        int currVal=1;
        int ans=0;
        for(auto &i:vec) {
            char ch=i.first;
            int freq=i.second;
            if(currNumsAvail>0) {
                currNumsAvail--;
                ans+=(currVal*freq);
            } else {
                currNumsAvail=8;
                currVal++;
                currNumsAvail--;
                ans+=(currVal*freq);
            }
        }
        return ans;
    }
};