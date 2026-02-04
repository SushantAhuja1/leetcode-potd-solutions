class Solution {
public:
    #define ll long long
    int n;
    vector<ll> leftBest;
    vector<ll> rightBest;
    vector<ll> prefixSum;
    ll ans = LLONG_MIN;

    long long maxSumTrionic(vector<int>& nums) {
        n = nums.size();
        if (n < 3) return -1; // Basic safety, though n is likely larger

        leftBest.resize(n);
        rightBest.resize(n);
        prefixSum.resize(n, 0);

        // 1. Build Prefix Sums
        prefixSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefixSum[i] = 1ll * prefixSum[i - 1] + 1ll * nums[i];
        }

        // 2. Build Left Best (Kadane's for increasing ending at i)
        leftBest[0] = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] < nums[i]) {
                leftBest[i] = max(1ll * nums[i], leftBest[i - 1] + 1ll * nums[i]);
            } else {
                leftBest[i] = 1ll * nums[i];
            }
        }

        // 3. Build Right Best (Kadane's for increasing starting at i)
        rightBest[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i + 1] > nums[i]) {
                rightBest[i] = max(1ll * nums[i], rightBest[i + 1] + 1ll * nums[i]);
            } else {
                rightBest[i] = 1ll * nums[i];
            }
        }

        // 4. Find Valleys and Calculate Answer
        int i = 1;
        while (i < n - 1) {
            // Check for start of a drop
            if (nums[i] < nums[i - 1]) {
                int p = i - 1; // Peak index

                // Slide down to find the Valley
                while (i < n - 1 && nums[i + 1] < nums[i]) {
                    i++;
                }
                int q = i; // Valley index

                // --- KEY FIX STARTS HERE ---
                // We must have a valid left leg (p > 0) and valid right leg (q < n-1).
                // Also, strictly ensure p is a Peak (rising from left) and q is a Valley (rising to right).
                if (p > 0 && q < n - 1 && nums[p] > nums[p-1] && nums[q] < nums[q+1]) {
                    
                    // Force the left leg to extend from p-1 to p
                    ll leg1 = leftBest[p - 1] + nums[p];

                    // Force the right leg to extend from q to q+1
                    ll leg3 = rightBest[q + 1] + nums[q];

                    // Middle part (strictly between p and q)
                    ll midSum = 0;
                    if (q > p + 1) {
                        midSum = prefixSum[q - 1] - prefixSum[p];
                    }

                    ans = max(ans, leg1 + leg3 + midSum);
                }
                // --- KEY FIX ENDS HERE ---
            }
            i++;
        }

        return ans;
    }
};