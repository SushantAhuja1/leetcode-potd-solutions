class Solution {
public:
    int n;
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        n=matrix.size();
        vector<int>ans(n,0);
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(matrix[i][j]==0) continue;
                else {
                    ans[i]++;
                    ans[j]++;
                }
            }
        }
        for(int i=0;i<n;i++) {
            ans[i]/=2;
        }
        return ans;
    }
};