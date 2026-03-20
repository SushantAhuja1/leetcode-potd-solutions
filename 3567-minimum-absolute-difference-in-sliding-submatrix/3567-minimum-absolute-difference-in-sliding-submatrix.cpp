class Solution {
public:
    int m,n;
    vector<vector<int>> ans;
    vector<int>temp;
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        m=grid.size();
        n=grid[0].size();
        ans.resize(m-k+1,vector<int>(n-k+1,0));
        int row=0,col=0;
        for(int i=0;i<=m-k;i++) {
            for(int j=0;j<=n-k;j++) {
                set<int>st;
                for(int l=i;l<=i+k-1;l++) {
                    for(int o=j;o<=j+k-1;o++) {
                        st.insert(grid[l][o]);
                    }
                }
                int mini=1e9;
                vector<int>tmp;
                for(auto &i:st) tmp.push_back(i);
                int sz=tmp.size();
                if(sz==1) mini=0;
                else {
                    for(int i=1;i<sz;i++) {
                        mini=min(mini,tmp[i]-tmp[i-1]);
                    }
                }
                ans[row][col]=mini;
                col++;
                if(col==n-k+1) {
                    col=0;
                    row++;
                }
            }
        }
        return ans;
    }
};