class Solution {
public:
    int m,n,cnt=0;
    bool isPossible(int i,int j,vector<vector<int>>& mat) {
        int cnt1=0;
        for(int x=0;x<n;x++) {
            if(mat[i][x]==1) cnt1++;
            if(cnt1>1) return false;
        }
        cnt1=0;
        for(int y=0;y<m;y++) {
            if(mat[y][j]==1) cnt1++;
            if(cnt1>1) return false;
        }
        return true;
    }
    int numSpecial(vector<vector<int>>& mat) {
        m=mat.size();
        n=mat[0].size();
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(mat[i][j]==0) continue;
                else {
                    if(isPossible(i,j,mat)) {
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};