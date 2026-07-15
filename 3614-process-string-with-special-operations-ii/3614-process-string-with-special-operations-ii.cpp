class Solution {
public:
    #define ll long long
    char processStr(string s, long long k) {
        int n=s.length();
        ll len=0;
        for(char &ch:s) {
            if(ch>='a' && ch<='z') len++;
            else if(ch=='#') len*=2;
            else if(ch=='*') {
                if(len>0) 
                    len--;
            }
            else continue;
        }
        if(k>=len) return '.';
        for(int i=n-1;i>=0;i--) {
            if(s[i]=='*') {
                len++;
            } else if(s[i]=='%') {
                k=len-k-1;
            } else if(s[i]=='#') {
                len=len/2;
                if(k>=len)
                    k=k-len;
            } else {
                len--;
            }
            if(k==len) return s[i];
        }
        return '.';
    }
};