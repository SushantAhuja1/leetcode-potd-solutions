class Solution {
public:
#define ll long long
#define mod (int)(1e9 + 7)
    int maxN = 5005;
    vector<ll> fact;
    vector<ll> invFact;
    // modular exponentiation
    ll power(ll base, ll exp) {
        ll res = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1)
                res = (res * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }
    void preCompute() {
        fact[0] = 1;
        invFact[0] = 1;
        for (int i = 1; i < maxN; i++) {
            fact[i] = (fact[i - 1] * i) % mod;
        }
        invFact[maxN - 1] = power(fact[maxN - 1], mod - 2);
        for (int i = maxN - 2; i >= 1; i--) {
            invFact[i] = (invFact[i + 1] * (i + 1)) % mod;
        }
    }
    string smallestPalindrome(string s, int k) {
        fact.resize(maxN);
        invFact.resize(maxN);
        preCompute();
        vector<int> freq(26, 0);
        int n = s.length();
        for (int i = 0; i < n; i++) {
            int idx = s[i] - 'a';
            freq[idx]++;
        }
        int halfLengthToForm = n / 2;
        int oddFreq = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2) {
                oddFreq = freq[i];
                break;
            }
        }
        ll possibleStrings = fact[halfLengthToForm];
        for (int i = 0; i < 26; i++) {
            possibleStrings = (possibleStrings * invFact[freq[i] / 2]) % mod;
        }
        if (k > possibleStrings)
            return "";
        vector<int> halfFreq(26, 0);
        int oddChar = -1;
        for (int i = 0; i < 26; i++) {
            halfFreq[i] = freq[i] / 2;
            if (freq[i] % 2 != 0) {
                oddChar = i;
            }
        }
        string firstHalf = "";
        int remainingLength = halfLengthToForm;
        for (int pos = 0; pos < halfLengthToForm; pos++) {
            for (int i = 0; i < 26; i++) {
                if (halfFreq[i] > 0) {
                    halfFreq[i]--;
                    // Replace lines 67-72 with this block:
                    long long possibleStrings = 1;
                    int n = 0; // Tracks the length built so far in the
                               // combination formula
                    for (int j = 0; j < 26; j++) {
                        if (halfFreq[j] > 0) {
                            for (int x = 1; x <= halfFreq[j]; x++) {
                                // Calculate exact permutations safely using
                                // __int128
                                __int128 next_val =
                                    (__int128)possibleStrings * (n + x) / x;

                                if (next_val > k) {
                                    possibleStrings =
                                        k + 1; // Cap it so it never overflows
                                } else {
                                    possibleStrings = (long long)next_val;
                                }
                            }
                            n += halfFreq[j];
                        }
                    }
                    if (k > possibleStrings) {
                        k -= possibleStrings;
                        halfFreq[i]++;
                    } else {
                        firstHalf += (char)('a' + i);
                        remainingLength--;
                        break;
                    }
                }
            }
        }
        string ans = firstHalf;
        if (oddChar != -1) {
            ans += (char)(oddChar + 'a');
        }
        string revHalf = firstHalf;
        reverse(revHalf.begin(), revHalf.end());
        ans += revHalf;
        return ans;
    }
};

// abba
// 4!/2!*2! => 24/4=> 6
// _,_ => 2! = 2
// abba
// baab
// build only half -> focus
// a->2,b->2 -> no odd char => total=4 so i need to focus only on first 2
// _ , _ => {a,b} => start with a or start with b
// a_
// b_

// bacab => a=2,b=2,c=1 -> c=>odd char
// total=5, 5/2=> 2 and then c will come
// _,_,c
// 2! => 2

// abcdcba -> a=2,b=2,c=2,d=1
// total=7 -> 7/2=>3+d
// {_,_,_},d
// a,b,c -> a,_,_ -> a,b,c || a,c,b
// b,_,_ -> b,a,c || b,c,a
//

// aabcdcbaa a=4,b=2,c=2,d=1
// total=9/2=>4+d
// _,_,_,_,d {a,a,b,c} => available chars for half string
// total formed => 4!/2!=> 12 strings
// _,_,_,_,d {a,a,b,c}
// start with a => a,_,_,_,d => 3! = 6 (k-6) => (2)
// start with b => b,_,_,_,d => 3!/2! = 3>k so ans will start with b

// b,_,_,_,d {a,a,c}
// start with a => b,a,_,_,d => 2! => 2<=k
// b,a,_,_,d {a,c}
// start with a => b,a,a,_,d => 1