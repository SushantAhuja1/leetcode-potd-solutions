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
        if (n < 3) return -1; 

        leftBest.resize(n);
        rightBest.resize(n);
        prefixSum.resize(n, 0);

        
        prefixSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefixSum[i] = 1ll * prefixSum[i - 1] + 1ll * nums[i];
        }

        
        leftBest[0] = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] < nums[i]) {
                leftBest[i] = max(1ll * nums[i], leftBest[i - 1] + 1ll * nums[i]);
            } else {
                leftBest[i] = 1ll * nums[i];
            }
        }

        
        rightBest[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i + 1] > nums[i]) {
                rightBest[i] = max(1ll * nums[i], rightBest[i + 1] + 1ll * nums[i]);
            } else {
                rightBest[i] = 1ll * nums[i];
            }
        }

        
        int i = 1;
        while (i < n - 1) {
            
            if (nums[i] < nums[i - 1]) {
                int p = i - 1; 

                
                while (i < n - 1 && nums[i + 1] < nums[i]) {
                    i++;
                }
                int q = i; 

                
                if (p > 0 && q < n - 1 && nums[p] > nums[p-1] && nums[q] < nums[q+1]) {
                    
                    
                    ll leg1 = leftBest[p - 1] + nums[p];

                    
                    ll leg3 = rightBest[q + 1] + nums[q];

                    
                    ll midSum = 0;
                    if (q > p + 1) {
                        midSum = prefixSum[q - 1] - prefixSum[p];
                    }

                    ans = max(ans, leg1 + leg3 + midSum);
                }
            }
            i++;
        }

        return ans;
    }
};