class Solution {
public: 
    int m,n;
    #define ll long long
    bool canPartitionGrid(vector<vector<int>>& grid) {
        m=grid.size(),n=grid[0].size();
        vector<vector<ll>>ps(m,vector<ll>(n,0ll));
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                ps[i][j]=grid[i][j];
                if(i>0) ps[i][j]+=ps[i-1][j];
                if(j>0) ps[i][j]+=ps[i][j-1];
                if(i>0 && j>0) ps[i][j]-=ps[i-1][j-1];
            }
        }
        // cout<<"Printing ps : "<<endl;
        // for(int i=0;i<m;i++) {
        //     for(int j=0;j<n;j++) {
        //         cout<<ps[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // all rows
        for(int i=1;i<m;i++) {
            ll top=ps[i-1][n-1];
            ll below=ps[m-1][n-1]-top;
            if(top==below) return 1;
        }
        // all col
        for(int i=1;i<n;i++) {
            ll left=ps[m-1][i-1];
            ll right=ps[m-1][n-1]-left;
            if(left==right) return 1;
        }
        return 0;
    }
};