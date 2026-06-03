class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size(),cnt=0,i=0,j=0,ans=0;
        while(j<n) {
            if(nums[j]==0) {
                cnt++;
            }
            while(cnt>k) {
                ans=max(ans,j-i);
                if(nums[i]==0) {
                    cnt--;
                }
                i++;
            }
            j++;
        }
        ans=max(ans,j-i);
        return ans;
    }
};