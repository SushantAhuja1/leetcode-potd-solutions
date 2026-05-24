class Solution {
public:
    int n;
    vector<int>dp;
    int solve(vector<int>& arr, int d, int idx) {
        if(dp[idx]!=-1) return dp[idx];
        int ans=1;
        //jump-forward
        for(int i=1;i<=d && idx+i<n;i++) {
            if(arr[idx+i]>=arr[idx]) break;
            ans=max(ans,1+solve(arr,d,idx+i));
        }
        //jump-backward
        for(int i=1;i<=d && idx-i>=0;i++) {
            if(arr[idx-i]>=arr[idx]) break;
            ans=max(ans,1+solve(arr,d,idx-i));
        }
        return dp[idx]=ans;
    }
    int maxJumps(vector<int>& arr, int d) {
        n=arr.size();
        int maxVisits=0;
        dp.assign(n, -1);
        for(int i=0;i<n;i++) {
            int visits=solve(arr,d,i);
            maxVisits=max(maxVisits,visits);
        }
        return maxVisits;
    }
};