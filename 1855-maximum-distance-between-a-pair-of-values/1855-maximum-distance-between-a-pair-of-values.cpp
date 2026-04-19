class Solution {
public:
    int findIndex(vector<int>& nums2, int val) {
        int low=0,high=nums2.size()-1,ans=high;
        while(low<=high) {
            int mid=low+(high-low)/2;
            if(nums2[mid]<val) {
                high=mid-1;
            }
            else {
                ans=mid;
                low=mid+1;
            }
        }
        return ans;
    }
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int ans=0;
        // nlog(m)
        for(int i=0;i<n;i++) {
            int val=nums1[i];
            int idx=findIndex(nums2,val);
            if(idx<i || val>nums2[idx]) continue;
            else {
                int dist=idx-i;
                ans=max(ans,dist);
            }       
        }
        return ans;
    }
};