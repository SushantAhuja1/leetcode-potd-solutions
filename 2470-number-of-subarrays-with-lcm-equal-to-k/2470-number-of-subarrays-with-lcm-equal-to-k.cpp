class Solution {
public:
    #define MAX 1000
    vector<int> isPrime;
    vector<int> primes;
    unordered_map<int, int> kPrimeFactorization;
    void soe() {
        isPrime[0] = 0;
        isPrime[1] = 0;
        for (int i = 2; i <= MAX; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= MAX; j += i) {
                    if (isPrime[j]) {
                        isPrime[j] = 0;
                    }
                }
                primes.push_back(i);
            }
        }
    }
    void getPrimeFactorizationForK(int k) {
        kPrimeFactorization.clear();
        for (auto &i : primes) {
            int cnt = 0;
            while (k % i == 0 && k > 0) {
                cnt++;
                k /= i;
            }
            if (cnt) kPrimeFactorization[i] = cnt;
        }
    }
    unordered_map<int, int> getPrimeFactorization(int x) {
        unordered_map<int, int> fact;
        for (auto &i : primes) {
            if (x == 1) break;
            int cnt = 0;
            while (x % i == 0 && x > 0) {
                cnt++;
                x /= i;
            }
            if (cnt) fact[i] = cnt;
        }
        return fact;
    }
    bool isMatch(unordered_map<int, int>& currentLCM) {
        if (currentLCM.size() != kPrimeFactorization.size()) return false;
        for (auto &i : kPrimeFactorization) {
            if (currentLCM[i.first] != i.second) return false;
        }
        return true;
    }
    bool isExceeding(unordered_map<int, int>& currentLCM) {
        for (auto &i : currentLCM) {
            if (i.second > kPrimeFactorization[i.first]) return true;
        }
        return false;
    }
    int subarrayLCM(vector<int>& nums, int k) {
        isPrime.assign(MAX + 1, 1); 
        soe();
        getPrimeFactorizationForK(k);
        int n = nums.size(), cnt = 0;
        for (int i = 0; i < n; i++) {
            unordered_map<int, int> currentLCMFactorization;
            for (int j = i; j < n; j++) {
                if (k % nums[j] != 0) {
                    break;
                }
                unordered_map<int, int> numFact = getPrimeFactorization(nums[j]);
                for (auto &pair : numFact) {
                    currentLCMFactorization[pair.first] = max(currentLCMFactorization[pair.first], pair.second);
                }
                if (isExceeding(currentLCMFactorization)) {
                    break;
                }
                if (isMatch(currentLCMFactorization)) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};