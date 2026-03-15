class Solution {
public:
    int n;
    unordered_map<int,int>mp;
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        n=nums1.size();
        for(auto &i:nums1) mp[i]++;
        for(auto &i:nums2) mp[i]++;
        for(auto &i:mp) {
            if(i.second%2) return -1;
        }
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        if(nums1==nums2) return 0;
        unordered_map<int,int>f1;
        for(auto &i:nums1) f1[i]++;
        int ans=0;
        for(auto &i:mp) {
            int curr=i.first;
            int total=i.second;
            int req=total/2;
            int cnt1=f1[curr];
            if(cnt1>req) {
                int swaps=(cnt1-req);
                ans+=swaps;
            }
        }
        return ans;
    }
};

//[10,10]    
//[20,20]

//[1,1,1,1]   -> [1,1,1,2] 
//[1,1,2,2]   -> [1,1,1,2]