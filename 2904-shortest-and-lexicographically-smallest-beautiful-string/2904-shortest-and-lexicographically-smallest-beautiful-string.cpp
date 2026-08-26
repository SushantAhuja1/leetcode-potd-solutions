class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n=s.length();
        string ans(n,'1');
        int L=n;
        vector<int>cnt1(n);
        cnt1[0]=(s[0]=='1'?1:0);
        for(int i=1;i<n;i++) {
            if(s[i]=='1') {
                cnt1[i]=1+cnt1[i-1];
            } else {
                cnt1[i]=cnt1[i-1];
            }
        }
        if(cnt1[n-1]==n) {
            return string(k,'1');
        }
        for(int i=0;i<n;i++) {
            for(int len=1;len<=n-i;len++) {
                int j=i+len-1;
                int ones=cnt1[j]-(i-1>=0?cnt1[i-1]:0);
                if(ones==k) {
                    string subStr=s.substr(i,len);
                   if(len<L) {
                    ans=subStr;
                    L=len;
                   } else if(len==L) {
                    ans=min(ans,subStr);
                   }
                }
            }
        }
        return ans==string(n,'1')?"":ans;
    }
};