#define mod (int)(1e9 + 7)

class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int xorr = 0;

        for (auto& qry : queries) {
            int l = qry[0], r = qry[1], k = qry[2], v = qry[3];
            for (int idx = l; idx <= r && idx < n; idx += k) {
                nums[idx] = (1LL * nums[idx] * v) % mod; // use 1LL to avoid overflow
            }

            // Debug printing (optional)
            // cout << "Printing nums : ";
            // for (auto i : nums) {
            //     cout << i << " ";
            // }
            // cout << endl;
        }

        for (auto& ele : nums) {
            xorr ^= ele;
        }
        return xorr;
    }
};
