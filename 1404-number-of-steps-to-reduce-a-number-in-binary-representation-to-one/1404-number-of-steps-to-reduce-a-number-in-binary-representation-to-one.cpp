class Solution {
public:
    int n;
    bool isOne(string &s) {
        bool b=true;
        for(int i=0;i<n-1;i++) 
        {
            if(s[i]=='1') 
            {
                b=false;
                break;
            }
        }
        return b&&(s[n-1]=='1');
    }
    int numSteps(string s) {
        n=s.length();
        int cnt=0;
        while(!isOne(s)) 
        {
            n=s.length();
            if(s[n-1]=='1') 
            {
                int x=n-1;
                while(x>=0 && s[x]=='1') 
                {
                    s[x]='0';
                    x--;
                }
                if(x>=0) 
                {
                    s[x]='1';
                } 
                else 
                {
                    s='1'+s;
                }
                cnt++;
            } 
            else 
            {
                char curr=s[0];
                s[0]='0';
                for(int i=1;i<n;i++) 
                {
                    char prev=s[i];
                    s[i]=curr;
                    curr=prev;
                }
                cnt++;
            }
        }
        return cnt;
    }
};