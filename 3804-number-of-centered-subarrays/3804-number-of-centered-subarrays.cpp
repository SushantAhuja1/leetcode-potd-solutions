class Solution {
public:
    int n;
    vector<int>ps;
    int ans;
    int centeredSubarrays(vector<int>& nums) {
        n=nums.size();
        ps.resize(n,0);
        ps[0]=nums[0];
        ans=n;
        for(int i=1;i<n;i++) ps[i]=ps[i-1]+nums[i];
        for(int r=0;r<n;r++) {
            for(int l=r-1;l>=0;l--) {
                int sum=ps[r]-((l-1>=0)?ps[l-1]:0);
                for(int k=l;k<=r;k++) {
                    if(sum==nums[k]) {
                        ans++;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};