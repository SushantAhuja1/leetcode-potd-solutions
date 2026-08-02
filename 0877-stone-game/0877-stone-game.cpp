class Solution {
public:
    int t[501][501];
    int solve(int i, int j, vector<int>& piles) {
        if(i==j) return piles[i];
        if(t[i][j]!=-1) return t[i][j];
        int takeFront=piles[i]-solve(i+1,j,piles);
        int takeLast=piles[j]-solve(i,j-1,piles);
        return t[i][j]=max(takeFront,takeLast);
    }
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        memset(t,-1,sizeof(t));
        int res=solve(0,n-1,piles);
        return res>=0?true:false;
    }
};