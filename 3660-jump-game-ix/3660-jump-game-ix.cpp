class Solution {
public: 
    int n;
    vector<int>ans;
    vector<int>prefixMax;
    vector<int>suffixMin;
    vector<int> maxValue(vector<int>& nums) {
        n=nums.size();
        ans.resize(n,0);
        prefixMax.resize(n,0);
        suffixMin.resize(n,0);
        prefixMax[0]=nums[0];
        for(int i=1;i<n;i++) {
            prefixMax[i]=max(prefixMax[i-1],nums[i]);
        }
        suffixMin[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--) {
            suffixMin[i]=min(suffixMin[i+1],nums[i]);
        }
        ans[n-1]=prefixMax[n-1];
        for(int i=n-2;i>=0;i--) {
            if(prefixMax[i]<=suffixMin[i+1]) {
                ans[i]=prefixMax[i];
            } else {
                ans[i]=ans[i+1];
            }
        }
        return ans;
    }
};