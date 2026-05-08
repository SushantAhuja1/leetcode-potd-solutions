class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        int maxElement = *max_element(nums.begin(), nums.end());
        // SOE
        vector<int> isPrime(maxElement + 1, 1);
        isPrime[0] = 0;
        isPrime[1] = 0;
        for (int i = 2; i * i <= maxElement; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= maxElement; j += i) {
                    isPrime[j] = 0;
                }
            }
        }
        vector<int> visited(n, 0);
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        queue<int> q;
        visited[0] = 1;
        q.push(0);
        unordered_set<int> usedPrimes;
        int t = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                int i = q.front();
                q.pop();
                if (i == n - 1)
                    return t;
                if (i - 1 >= 0 && !visited[i - 1]) {
                    visited[i - 1] = 1;
                    q.push(i - 1);
                }
                if (i + 1 < n && !visited[i + 1]) {
                    visited[i + 1] = 1;
                    q.push(i + 1);
                }
                if (isPrime[nums[i]] && !usedPrimes.count(nums[i])) {
                    usedPrimes.insert(nums[i]);
                    for (int multiple = nums[i]; multiple <= maxElement;
                         multiple += nums[i]) {
                        if (!mp.count(multiple)) {
                            continue;
                        } else {
                            for (auto& j : mp[multiple]) {
                                if (!visited[j]) {
                                    visited[j] = 1;
                                    q.push(j);
                                }
                            }
                        }
                    }
                }
            }
            t++;
        }
        return t;
    }
};