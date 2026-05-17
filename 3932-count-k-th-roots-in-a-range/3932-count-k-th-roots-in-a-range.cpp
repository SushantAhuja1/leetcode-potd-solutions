class Solution {
public:
    map<int,int>mp;
    bool find(int mid,int power) {
        long long res=1;
        for(int i=1;i<=power;i++) {
            res=res*mid;
            if(res>1e9) return false;
        }
        return true;
    }
    int countKthRoots(int l, int r, int k) {
        mp[1]=(int)1e9; //1e9^1<=1e9
        for(int power=2;power<=30;power++) {
            int low=0,high=1e9,ans=low;
            while(low<=high) {
                int mid=low+(high-low)/2;
                //mid*mid*mid.....power times
                bool isLessThanMax=find(mid,power);
                if(isLessThanMax) {
                    ans=mid;
                    low=mid+1;
                } else {
                    high=mid-1;
                }
            }
            mp[power]=ans;
        }
        // cout<<"Printing mp : "<<endl;
        // for(auto &i:mp) {
        //     cout<<i.first<<" : "<<i.second<<endl;
        // }
        if(r==(int)1e9 && k==1) return r-l+1;
        int cnt=0;
        for(int i=1;i<=mp[k];i++) {
            long long val=i;
            for(int j=2;j<=k;j++) {
                val=val*i;
            }
            // cout<<"i : "<<i<<" , val : "<<val<<endl;
            if(val>=l && val<=r) cnt++;
            else if(val>r) break;
        }
        if(l==0) cnt++;
        return cnt;
    }
};