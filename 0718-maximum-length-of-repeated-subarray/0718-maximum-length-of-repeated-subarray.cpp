class Solution {
public:
    int n,m;
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        n=nums1.size();
        m=nums2.size();
        int ans=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                int cnt=0;
                if(nums2[j]==nums1[i]) {
                    //start for this j
                    int i1=i,i2=j;
                    while(i1<n && i2<m && nums1[i1]==nums2[i2]) {
                        cnt++;
                        i1++;
                        i2++;
                    }
                    ans=max(ans,cnt);
                }
            }
        }
        return ans;
    }
};