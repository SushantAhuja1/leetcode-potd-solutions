class Solution {
public:
    #define ll long long
    int n;
    vector<ll>prefixGcd;
    vector<int>maxi;
    ll sum=0;
    long long gcdSum(vector<int>& nums) {
        n=nums.size();
        prefixGcd.resize(n);
        maxi.resize(n);
        maxi[0]=nums[0];
        for(int i=1;i<n;i++) {
            maxi[i]=max(maxi[i-1],nums[i]);
        }
        for(int i=0;i<n;i++) {
            prefixGcd[i]=__gcd(nums[i],maxi[i]);
        }
        // cout<<"prefixGcd : "<<endl;
        // for(auto &i:prefixGcd) {
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        sort(prefixGcd.begin(),prefixGcd.end());
        // cout<<"prefixGcd sorted : "<<endl;
        // for(auto &i:prefixGcd) {
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        int i=0,j=n-1;
        while(i<j) {
            ll curr=__gcd(prefixGcd[i],prefixGcd[j]);
            sum+=curr;
            i++;
            j--;
        }
        return sum;
    }
};