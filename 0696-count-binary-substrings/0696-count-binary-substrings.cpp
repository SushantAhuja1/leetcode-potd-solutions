class Solution {
public:
    int n;
    int solve(string s) {
        int prevGrp=0;
        int currGrp=1;
        int ans=0;
        for(int i=1;i<n;i++) {
            if(s[i]==s[i-1]) {
                currGrp++;
            } else {
                ans+=min(currGrp,prevGrp);
                prevGrp=currGrp;
                currGrp=1;
            }
        }
        ans+=min(currGrp,prevGrp);
        return ans;
    }
    int countBinarySubstrings(string s) {
        n=s.length();
        return solve(s);
    }
}; 