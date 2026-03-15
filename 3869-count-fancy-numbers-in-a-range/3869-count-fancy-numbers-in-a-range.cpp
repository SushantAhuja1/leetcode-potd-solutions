class Solution {
public:
    #define ll long long 
    ll dp[16][2][10][140][2][4];
    bool check(int x) {
        string s=to_string(x);
        int n=s.length();
        for(int i=1;i<n;i++) {
            if(s[i]==s[i-1]) return false;
        }
        if(n<3) return true;
        bool inc=((s[1]-s[0])>0)?1:0;
        for(int i=2;i<n;i++) {
            bool curr=((s[i]-s[i-1])>0)?1:0;
            if(curr!=inc) return false;
        }
        return true;
    }
    ll solve(string &n,int pos,bool tight,int prevDigit,int sum,bool isLeading,int isMonotone) {
        if(pos>=n.length()) {
            return (check(sum) || isMonotone!=3);
        }   
        if(dp[pos][tight][prevDigit][sum][isLeading][isMonotone]!=-1) return dp[pos][tight][prevDigit][sum][isLeading][isMonotone];
        int limit=tight?(n[pos]-'0'):9;
        ll ans=0;
        for(int d=0;d<=limit;d++) {
            bool newTight=tight&&(d==limit);
            int newIsMonotone;
            if(isMonotone==3) {
                newIsMonotone=3;
            } else if(isLeading) {
                newIsMonotone=0;
            } else if(!isLeading) {
                if(isMonotone==0) {
                    if(d>prevDigit) newIsMonotone=1;
                    else if(d<prevDigit) newIsMonotone=2;
                    else newIsMonotone=3;
                } else if(isMonotone==1) {
                    if(d>prevDigit) newIsMonotone=1;
                    else newIsMonotone=3;
                } else {
                    if(d<prevDigit) newIsMonotone=2;
                    else newIsMonotone=3;
                }
            }
            ans+=solve(n,pos+1,newTight,d,sum+d,isLeading&&(d==0),newIsMonotone);
        }
        return dp[pos][tight][prevDigit][sum][isLeading][isMonotone]=ans;
    }
    ll fun(ll n) {
        if(n<0) return 0;
        string str=to_string(n);
        ll ans=solve(str,0,true,0,0,true,0);
        return ans;
    }
    long long countFancy(long long l, long long r) {
        memset(dp,-1,sizeof(dp));
        ll solveR=fun(r);
        memset(dp,-1,sizeof(dp));
        ll solveL=fun(l-1);
        return solveR-solveL;
    }
};