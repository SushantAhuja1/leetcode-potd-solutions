class Solution {
public: 
    #define ll long long
    int n;
    vector<int>mx;
    vector<ll>prefixGCD;
    long long gcdSum(vector<int>& nums) {
        n=nums.size();
        mx.resize(n);
        prefixGCD.resize(n);
        mx[0]=nums[0];
        for(int i=1;i<n;i++) {
            mx[i]=max(mx[i-1],nums[i]);
        }
        for(int i=0;i<n;i++) {
            prefixGCD[i]=__gcd(nums[i],mx[i]);
        }
        sort(prefixGCD.begin(),prefixGCD.end());
        int i=0,j=n-1;
        ll sumGCD=0;
        while(i<j) {
            ll currGCD=__gcd(prefixGCD[i],prefixGCD[j]);
            sumGCD+=currGCD;
            i++;
            j--;
        }
        return sumGCD;
    }
};