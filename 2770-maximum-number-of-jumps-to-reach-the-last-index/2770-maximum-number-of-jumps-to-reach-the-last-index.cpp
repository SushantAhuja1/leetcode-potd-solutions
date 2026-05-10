class Solution {
public:
    int n;
    vector<int> dp;
    
    int solve(vector<int>& nums, int target, int i) {
        if(i >= n - 1) return 0; // reached end
        if(dp[i] != -1) return dp[i];
        
        int curr = nums[i];
        int ans = INT_MIN;
        for(int j = i + 1; j < n; j++) {
            int next = nums[j];
            if(abs(next - curr) <= target) {
                ans = max(ans, 1 + solve(nums, target, j));
            }
        }
        dp[i] = (ans == INT_MIN ? INT_MIN : ans);
        return dp[i];
    }
    
    int maximumJumps(vector<int>& nums, int target) {
        n = nums.size();
        dp.assign(n, -1);
        int ans = solve(nums, target, 0);
        return ans <= 0 ? -1 : ans;
    }
};
