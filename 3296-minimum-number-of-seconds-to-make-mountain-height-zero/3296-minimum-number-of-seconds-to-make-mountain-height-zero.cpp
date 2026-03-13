class Solution {
public:
    #define ll long long
    int n;
    bool check(ll mid, int mountainHeight, vector<int>& workerTimes) {
        //(1+2+3+4+....x)*(workerTimes[i])<=mid
        //(x*(x+1))*workerTimes[i]<=mid*2
        //x*(x+1)<=2*mid/workerTimes[i]
        ll totalHeightReduced=0;
        for(int i=0;i<n;i++) {
            ll w=workerTimes[i];
            ll x=(-1+sqrt(1+8.0*mid/w))/2;
            totalHeightReduced+=x;
            if(totalHeightReduced>=mountainHeight) return true;
        }
        return false;
    }
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        sort(workerTimes.begin(),workerTimes.end());
        n=workerTimes.size();
        ll low=1,high=1e18,ans=high;
        while(low<=high) {
            ll mid=low+(high-low)/2;
            bool res=check(mid,mountainHeight,workerTimes);
            if(res) {
                ans=mid;
                high=mid-1;
            } else {
                low=mid+1;
            }
        }
        return ans;
    }
};