class Solution {
public:
    #define ll long long
    #define mod (int)(1e9+7)
    unordered_map<int,int>bits;
    void calculateBits(int n) {
        for(int i=1;i<=n;i++) {
            int numberOfBits=log2(i)+1;
            bits[i]=numberOfBits;
        }
    }
    ll power(int base,int exponent) {
        if(exponent==0) return 1;
        if(exponent==1) return base;
        ll val=power(base,exponent/2);
        if(exponent%2==0) return (val%mod*val%mod)%mod;
        else return (base*(val%mod)*(val%mod))%mod;
    }
    int concatenatedBinary(int n) {
        calculateBits(n);
        ll ans=0;
        for(int i=1;i<=n;i++) {
            ans=((ans*power(2,bits[i])%mod)+i%mod)%mod;
        }
        return (int)ans;
    }
};