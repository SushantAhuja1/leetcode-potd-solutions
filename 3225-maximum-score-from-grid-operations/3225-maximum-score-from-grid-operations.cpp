class Solution {
public:
    using ll = long long;

    int n;
    vector<vector<ll>> pref;
    vector<vector<vector<ll>>> dp;

    ll solve(int prevTaken, int prevLen, int col) {
        // Java uses columns from 1 to n
        if (col == n + 1) return 0;

        ll &res = dp[prevTaken][prevLen][col];
        if (res != -1) return res;

        res = 0;

        for (int len = 0; len <= n; ++len) {
            ll prevAns = 0, currAns = 0;

            // Contribution from previous column
            if (prevTaken == 0 && col > 1 && len > prevLen) {
                prevAns = pref[len][col - 1] - pref[prevLen][col - 1];
            }

            // Contribution from current column
            if (prevLen > len) {
                currAns = pref[prevLen][col] - pref[len][col];
            }

            ll ans1 = prevAns + currAns + solve(1, len, col + 1);
            ll ans2 = prevAns + solve(0, len, col + 1);

            res = max(res, max(ans1, ans2));
        }

        return res;
    }

    long long maximumScore(vector<vector<int>>& grid) {
        n = grid.size();

        // 1-based prefix sums: pref[i][j] = sum of first i elements in column (j-1)
        pref.assign(n + 1, vector<ll>(n + 1, 0));

        for (int j = 0; j < n; ++j) {
            for (int i = 1; i <= n; ++i) {
                pref[i][j + 1] = pref[i - 1][j + 1] + grid[i - 1][j];
            }
        }

        dp.assign(2, vector<vector<ll>>(n + 1, vector<ll>(n + 1, -1)));

        return solve(0, 0, 1);
    }
};