class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(),n=matrix[0].size(),i=0,j=n-1;
        while(i<m && j>=0) {
            int curr=matrix[i][j];
            if(curr==target) return true;
            else if(curr>target) {
                j=j-1;
            } else {
                i=i+1;
            }
        }   
        return false;
    }
};