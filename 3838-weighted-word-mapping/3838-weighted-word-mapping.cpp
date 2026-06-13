class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        unordered_map<int,char>mp;
        for(int i=25;i>=0;i--) {
            mp[i]='a'+(25-i);
        }
        string ans="";
        int n=words.size();
        for(auto &word:words) {
            int sum=0;
            for(int i=0;i<word.size();i++) {
                int val=weights[word[i]-'a'];
                sum+=val;
            }
            sum=sum%26;
            ans+=mp[sum];
        }
        return ans;
    }
};

// 0->z
// 1->y
// 2->x
// 