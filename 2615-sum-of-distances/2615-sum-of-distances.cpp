class Solution {
public:
    #define ll long long
    vector<ll> ans;
    int n;
    unordered_map<int,vector<int>>mp;
    vector<ll>psum;
    vector<long long> distance(vector<int>& nums) {
        n=nums.size();
        ans.resize(n,0);
        for(int i=0;i<n;i++) {
            mp[nums[i]].push_back(i);
        }
        for(auto &i:mp) {
            int num=i.first;
            vector<int>temp=i.second;
            int m=temp.size();
            if(m==1) continue;
            else {
                psum.resize(m,0);
                psum[0]=temp[0];
                for(int j=1;j<m;j++) {
                    psum[j]=psum[j-1]+temp[j];
                }
                for(int j=0;j<m;j++) {
                    ll val=1ll*(j+1)*(temp[j])-psum[j]+1ll*(psum[m-1]-psum[j])-1ll*(m-1-j)*temp[j];
                    ans[temp[j]]=val;
                }
            }
        }
        return ans;
    }
};
// [1,3,1,1,2]
// 1 -> {0,2,3}
// 3 -> {1} -> 0
// 2 -> {4} -> 0

// idx=0 -> |0-2|+|0-3| = 5
// idx=2 -> |2-0|+|2-3| = 3
// idx=3 -> |3-0|+|3-2| = 4
// {0,2,3} -> array
// {0,2,5} -> prefixSum