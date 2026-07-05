class Solution {
public:
    #define ll long long
    #define mod (int)(1e9+7)
    int n,m;
    int t1[101][101];
    ll getNumberOfPaths(int target, vector<string>& board) {
        if(target<0) return 0;
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(target+1,0)));
        dp[0][0][0]=1;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if (board[i][j] == 'X') continue;
                if (i == 0 && j == 0) continue;
                int val = 0;
                if (board[i][j] >= '1' && board[i][j] <= '9') {
                    val = board[i][j] - '0';
                }
                for(int t=val;t<=target;t++) {
                    ll up=i-1>=0?dp[i-1][j][t-val]%mod:0;
                    ll left=(j-1>=0)?dp[i][j-1][t-val]%mod:0;
                    ll upLeft=(i-1>=0 && j-1>=0)?dp[i-1][j-1][t-val]%mod:0;
                    dp[i][j][t]=((up+left)%mod+upLeft)%mod;
                }
            }
        }
        return dp[n-1][m-1][target];
    }
    int getMaximumScore(int i, int j, vector<string>& board) {
        if(i==0 && j==0) return 0;
        if(i<0 || j<0 || board[i][j]=='X') return -1e9;
        if(t1[i][j]!=-1) return t1[i][j];
        int up=getMaximumScore(i-1,j,board);
        int left=getMaximumScore(i,j-1,board);
        int upLeft=getMaximumScore(i-1,j-1,board);
        int val=0;
        if(board[i][j]>='1' && board[i][j]<='9') {
            val=board[i][j]-'0';
        }
        return t1[i][j]=val+max({up,left,upLeft});
    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        n=board.size();
        m=board[0].size();
        memset(t1,-1,sizeof(t1));
        int maxScore=getMaximumScore(n-1,m-1,board);
        ll getPaths=getNumberOfPaths(maxScore,board)%mod;
        if(maxScore<0) return {0,0};
        return {maxScore,(int)getPaths};
    }
};