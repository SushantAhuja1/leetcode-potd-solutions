class Solution {
public:
    int m,n;
    int largestSubmatrix(vector<vector<int>>& matrix) {
        m=matrix.size();
        n=matrix[0].size();
        vector<vector<int>>arr(m,vector<int>(n,0));
        for(int col=0;col<n;col++) {
            int cnt=0;
            for(int row=0;row<m;row++) {
                if(matrix[row][col]==0) {
                    arr[row][col]=0;
                    cnt=0;
                } else {
                    cnt++;
                    arr[row][col]=cnt;
                }
            }
        }
        for(int r=0;r<m;r++) {
            sort(arr[r].begin(),arr[r].end(),greater<>());
        }
        int ans=0;
        for(int r=0;r<m;r++) {
            for(int c=0;c<n;c++) {
                ans=max(ans,arr[r][c]*(c+1));
            }
        }
        return ans;
    }
};

//converting the matrix into 
//0 0 1
//1 1 2
//2 0 3 

//sort the rows h1>=h2>=h3....

//0 0 1
//1 1 2
//0 2 3

//1 0 0
//2 1 1
//3 2 0
