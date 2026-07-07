class Solution {
public:
    #define ll long long
    #define mod (int)(1e9+7)
    #define t tuple<ll,ll,ll>
    vector<t>prefix;

    // Helper function to quickly calculate (base^exp) % mod
    ll power(ll base, ll exp) {
        ll res = 1;
        base = base % mod;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        vector<int>ans;
        int n=s.length();
        prefix.resize(n);
        prefix[0]={s[0]-'0',s[0]-'0',s[0]=='0'?1:0};
        
        for(int i=1;i<n;i++) {
            ll prevNum=get<0>(prefix[i-1])%mod;
            ll prevSum=get<1>(prefix[i-1])%mod;
            // Removed % mod here so we get the true count of zeros
            ll prevZeros=get<2>(prefix[i-1]); 
            
            int currDigit=s[i]-'0';
            ll currNum=prevNum%mod, currSum=prevSum%mod;
            
            if(currDigit!=0) {
                currNum=((currNum*10)%mod+currDigit%mod)%mod;
                currSum=(currSum%mod+currDigit)%mod;
            }
            ll currZeros=prevZeros+(currDigit==0);
            prefix[i]={currNum,currSum,currZeros};
        }
        
        for(auto &qry:queries) {
            int l=qry[0];
            int r=qry[1];
            auto [rnum,rsum,rzeros]=prefix[r];
            ll lnum=0,lsum=0;
            ll lzeros=0;
            
            if(l-1>=0) {
                lnum=get<0>(prefix[l-1])%mod;
                lsum=get<1>(prefix[l-1])%mod;
                lzeros=get<2>(prefix[l-1]); // Removed % mod here too
            }
            
            // --- REPLACED STRING MANIPULATION ---
            // 1. Find how many non-zero digits are strictly inside [l, r]
            ll totalElements = (r - l + 1);
            ll zerosInRange = rzeros - lzeros;
            ll nonZeroDigits = totalElements - zerosInRange;
            
            // 2. Shift lnum by 10^(nonZeroDigits) 
            ll shiftedLnum = (lnum * power(10, nonZeroDigits)) % mod;
            
            // 3. Subtract shifted lnum from rnum
            ll number = (rnum - shiftedLnum + mod) % mod;
            
            // 4. Multiply by sum difference
            ll val = (number * ((rsum - lsum + mod) % mod)) % mod;
            
            ans.push_back(val);
        }
        return ans;
    }
};