class Solution {
public:
    int m,n;
    vector<vector<int>>arr;
    bool areSimilar(vector<vector<int>>& mat, int k) {
        m=mat.size();
        n=mat[0].size();
        arr.resize(m,vector<int>(n,0));
        k%=n;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(i%2==0)
                    arr[i][((j-k)+n)%n]=mat[i][j];
                else 
                    arr[i][(j+k)%n]=mat[i][j];
            }
        }
        return arr==mat;
    }
};