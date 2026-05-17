class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        int n=s.length();
        for(int i=0;i<n-1;i++) {
            int a=s[i]-'0';
            int b=s[i+1]-'0';
            int diff=abs(a-b);
            if(diff>2) return 0;
        }
        return 1;
    }
};