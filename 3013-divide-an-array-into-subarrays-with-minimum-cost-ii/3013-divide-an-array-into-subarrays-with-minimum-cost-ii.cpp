class Solution {
public:
    #define ll long long
    multiset<ll>L,R;
    int n;
    ll ans=LLONG_MAX;
    ll sum=0;
    int target;
    void add(int val) {
        L.insert(val);
        sum+=val;
        if(L.size()>target) {
            ll ele=*L.rbegin();
            L.erase(prev(L.end()));
            sum-=ele;
            R.insert(ele);
        }
    }
    void remove(int val) {
        auto it=L.find(val);
        if(it!=L.end()) {
            L.erase(it);
            sum-=val;
        } else {
            R.erase(R.find(val));
        }
        if(L.size()<target && R.size()>0) {
            int smallest = *R.begin();
            L.insert(smallest);
            sum+=smallest;
            R.erase(R.begin());
        }
    }
    long long minimumCost(vector<int>& nums, int k, int dist) {
        n=nums.size();
        target=k-1;
        for(int i=1;i<n;i++) {
            add(nums[i]);
            if(i>dist+1) {
                remove(nums[i-(dist+1)]);
            }
            if(i>=k-1) {
                ans=min(ans,sum);
            }
        }
        return ans+nums[0];
    }
};