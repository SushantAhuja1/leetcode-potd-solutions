class Solution {
public:
    int t[21][21];
    int solve(int i,int j,vector<int>& nums) {
        if(i==j) return nums[i];
        if(t[i][j]!=-1) return t[i][j];
        int takeI=nums[i]-solve(i+1,j,nums);
        int takeJ=nums[j]-solve(i,j-1,nums);
        return t[i][j]=max(takeI,takeJ);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        memset(t,-1,sizeof(t));
        int res=solve(0,n-1,nums);
        return res>=0;
    }
};