class Solution {
public:
    #define ll long long
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int n=nums.size();
        int maxVal=*max_element(nums.begin(),nums.end());
        vector<int>divisorFreq(maxVal+1,0);
        for(int i=0;i<n;i++) {
            int num=nums[i];
            for(int j=1;j*j<=num;j++) {
                if(num%j==0) {
                    divisorFreq[j]++;
                    if(num/j!=j) {
                        divisorFreq[num/j]++;
                    }
                }
            }
        }
        vector<ll>pairsWithGCD(maxVal+1,0);
        for(int g=maxVal;g>=1;g--) {
            ll count=divisorFreq[g];
            pairsWithGCD[g]=(count*(count-1))/2;
            for(int multiple=2*g;multiple<=maxVal;multiple+=g) {
                pairsWithGCD[g]-=pairsWithGCD[multiple];
            }
        }
        vector<ll>prefixCountGCD(maxVal+1,0);
        for(int g=1;g<=maxVal;g++) {
            prefixCountGCD[g]=prefixCountGCD[g-1]+pairsWithGCD[g];
        }
        vector<int>result;
        for(ll idx:queries) {
            int l=1;
            int r=maxVal;
            int temp=1;
            while(l<=r) {
                int mid_gcd=l+(r-l)/2;
                if(prefixCountGCD[mid_gcd]>idx) {
                    temp=mid_gcd;
                    r=mid_gcd-1;
                } else {
                    l=mid_gcd+1;
                }
            }
            result.push_back(temp);
        }
        return result;
    }
};