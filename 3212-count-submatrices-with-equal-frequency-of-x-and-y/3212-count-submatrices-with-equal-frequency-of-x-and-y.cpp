class Solution {
public:
    int n,m;
    vector<vector<int>>x;
    vector<vector<int>>y;
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        n=grid.size();
        m=grid[0].size();
        x.resize(n,vector<int>(m,0));
        y.resize(n,vector<int>(m,0));
        x[0][0]=grid[0][0]=='X';
        y[0][0]=grid[0][0]=='Y';
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(i==0 && j==0) continue;
                else {
                    x[i][j]=(grid[i][j]=='X')
                        +(i>0?x[i-1][j]:0)
                        +(j>0?x[i][j-1]:0)
                        -(i>0 && j>0?x[i-1][j-1]:0);
                }
            }
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(i==0 && j==0) continue;
                else {
                    y[i][j]=(grid[i][j]=='Y')
                        +(i>0?y[i-1][j]:0)
                        +(j>0?y[i][j-1]:0)
                        -(i>0 && j>0?y[i-1][j-1]:0);
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(x[i][j]==y[i][j] && x[i][j]>0) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};