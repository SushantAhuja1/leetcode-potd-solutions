class Solution {
public:
    #define ll long long
    int m, n;
    const int mod = 1e9 + 7;
    
    vector<vector<pair<ll,ll>>> dp;
    
    pair<ll,ll> solve(int i, int j, vector<vector<int>>& grid) {
        if(i >= m || j >= n) return {LLONG_MIN, LLONG_MAX};
        
        if(dp[i][j].first != LLONG_MIN) return dp[i][j];
        
        if(i == m-1 && j == n-1) {
            return dp[i][j] = {grid[i][j], grid[i][j]};
        }
        
        auto right = solve(i, j+1, grid);
        auto down  = solve(i+1, j, grid);
        
        ll mx = LLONG_MIN, mn = LLONG_MAX;
        
        vector<ll> candidates;
        
        if(right.first != LLONG_MIN) {
            candidates.push_back(right.first);
            candidates.push_back(right.second);
        }
        if(down.first != LLONG_MIN) {
            candidates.push_back(down.first);
            candidates.push_back(down.second);
        }
        
        for(ll val : candidates) {
            ll prod = val * grid[i][j];
            mx = max(mx, prod);
            mn = min(mn, prod);
        }
        
        return dp[i][j] = {mx, mn};
    }
    
    int maxProductPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        dp.assign(m, vector<pair<ll,ll>>(n, {LLONG_MIN, LLONG_MAX}));
        
        auto res = solve(0, 0, grid);
        
        if(res.first < 0) return -1;
        return res.first % mod;
    }
};