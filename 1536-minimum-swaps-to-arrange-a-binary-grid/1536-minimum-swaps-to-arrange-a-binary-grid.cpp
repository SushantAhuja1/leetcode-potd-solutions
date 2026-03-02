class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int>nums;
        for(int i=0;i<n;i++) {
            int cnt=0;
            for(int j=n-1;j>=0;j--) {
                if(grid[i][j]==0) {
                    cnt++;
                } else {
                    break;
                }
            }
            nums.push_back(cnt);
        }
        //cnt operations
        int ans=0;
        for(int i=0;i<n;i++) {
            int currRow=i;
            int targetZeros=n-i-1;
            int currZeros=nums[i];
            //now find the first index in nums where ele >= targetZeros
            int idx=-1;
            for(int j=i;j<n;j++) {
                if(nums[j]>=targetZeros) {
                    idx=j;
                    break;
                }
            }
            if(idx==-1) return -1;
            ans+=(idx-i);
            for(int j=idx;j>i;j--) {
                swap(nums[j],nums[j-1]);
            }
        }
        return ans;
    }
};