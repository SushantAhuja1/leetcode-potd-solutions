class Solution {
public:
    int n;
    vector<int>pSum;
    int t[50001];
    int solve(int i, vector<int>& stoneValue) {
        if(i>=n) return 0;
        if(t[i]!=-1) return t[i];
        int ans=INT_MIN;
        for(int l=1;l<=min(3,n-i);l++) {
            int j=i+l-1;
            int score=pSum[j]-((i-1>=0)?pSum[i-1]:0);
            int currVal=score-solve(i+l,stoneValue);
            ans=max(ans,currVal);
        }
        return t[i]=ans;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        n=stoneValue.size();
        pSum.resize(n);
        pSum[0]=stoneValue[0];
        for(int i=1;i<n;i++) {
            pSum[i]=pSum[i-1]+stoneValue[i];
        }
        memset(t,-1,sizeof(t));
        int res=solve(0,stoneValue);
        if(res>0) {
            return "Alice";
        } else if(res==0) {
            return "Tie";
        } else {
            return "Bob";
        }
    }
};