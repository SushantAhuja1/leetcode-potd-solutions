class Solution {
public:
    int passwordStrength(string password) {
        unordered_map<char,int>mp;
        for(auto &i:password) {
            mp[i]++;
        }
        int ans=0;
        for(auto &i:mp) {
            char ch=i.first;
            if(ch>='a' && ch<='z') ans+=1;
            else if(ch>='A' && ch<='Z') ans+=2;
            else if(ch>='0' && ch<='9') ans+=3;
            else if(ch=='!' || ch=='@' || ch=='#' || ch=='$') ans+=5;
        }
        return ans;
    }
};