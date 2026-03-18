class Solution {
public:
    int n,m;
    vector<vector<int>>arr;
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        n=grid.size();
        m=grid[0].size();
        arr.resize(n,vector<int>(m,0));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                arr[i][j]=grid[i][j]
          + (i > 0 ? arr[i-1][j] : 0)
          + (j > 0 ? arr[i][j-1] : 0)
          - (i > 0 && j > 0 ? arr[i-1][j-1] : 0);
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
               if(arr[i][j]<=k) cnt++;
            }
        }
        return cnt;

    }
};