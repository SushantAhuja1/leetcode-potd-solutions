class Solution {
public:
    bool checkOnesSegment(string s) {
        int n=s.length();
        int ans=0;
        int cnt1=0;
        for(int i=0;i<n;) {
            int j=i;
            while(j<n && s[j]=='1') {
                j++;
                cnt1++;
            }
            if(cnt1) {
                ans++;
                i=j;
            } else {
                i++;
            }
            cnt1=0;
        }
        if(cnt1) ans++;
        return ans==1;
    }
};