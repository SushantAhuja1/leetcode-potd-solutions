class Solution {
public:
#define ll long long
#define mod (int)(1e9 + 7)
    unordered_map<int, int> bits;
    void calculateBits(int n) {
        for (int i = 1; i <= n; i++) {
            int numberOfBits = log2(i) + 1;
            bits[i] = numberOfBits;
        }
    }
    ll power(ll a, ll b) {
        long long result = 1;
        while (b) {
            if (b & 1)
                result = (result % mod * a % mod) % mod;
            a = (a % mod * a % mod) % mod;
            b >>= 1;
        }
        return result;
    }
    int concatenatedBinary(int n) {
        calculateBits(n);
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            ans = ((ans * power(2, bits[i]) % mod) + i % mod) % mod;
        }
        return (int)ans;
    }
};