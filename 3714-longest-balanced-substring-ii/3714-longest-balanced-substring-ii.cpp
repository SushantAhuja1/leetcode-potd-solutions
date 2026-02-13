class Solution {
public:
    int n;
    int helper(string &s,char ch1,char ch2) {
        int cnt1=0,cnt2=0,maxL=0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++) {
            if(s[i]!=ch1 && s[i]!=ch2) {
                mp.clear();
                cnt1=0;
                cnt2=0;
                continue;
            } else {
                if(s[i]==ch1) cnt1++;
                if(s[i]==ch2) cnt2++;
                if(cnt1==cnt2) maxL=max(maxL,cnt1+cnt2);
                int diff=cnt1-cnt2;
                if(mp.find(diff)!=mp.end()) {
                    maxL=max(maxL,i-mp[diff]);
                } else {
                    mp[diff]=i;
                }
            }
        }
        return maxL;
    }
    int longestBalanced(string s) {
        n=s.length();
        int maxL=0;
        int cnt=1;
        for(int i=1;i<n;i++) {
            if(s[i]==s[i-1]) {
                cnt++;
            } else {
                maxL=max(maxL,cnt);
                cnt=1;
            }
        }
        maxL=max(maxL,cnt);
        maxL=max(maxL,helper(s,'a','b'));
        maxL=max(maxL,helper(s,'b','c'));
        maxL=max(maxL,helper(s,'a','c'));
        int cntA=0,cntB=0,cntC=0;
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++) {
            if(s[i]=='a') cntA++;
            if(s[i]=='b') cntB++;
            if(s[i]=='c') cntC++;
            if(cntA==cntB && cntB==cntC) maxL=max(maxL,cntA+cntB+cntC);
            int diffAB = cntA-cntB;
            int diffBC = cntB-cntC;
            string key = to_string(diffAB)+"_"+to_string(diffBC);
            if(mp.find(key)!=mp.end()) {
                maxL=max(maxL,i-mp[key]);
            } else {
                mp[key]=i;
            }
        }
        return maxL;
    }
};