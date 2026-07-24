class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int maxXorr=2048;
        vector<bool>pairXorr(maxXorr,false);
        vector<bool>tripletXorr(maxXorr,false);
        int n=nums.size();
        for(int i=0;i<n;i++) {
            for(int j=i;j<n;j++) {
                pairXorr[nums[i]^nums[j]]=true;
            }
        }
        for(int i=0;i<maxXorr;i++) {
            if(!pairXorr[i]) continue;
            for(auto &j:nums) {
                tripletXorr[i^j]=true;
            }
        }
        int cnt=0;
        for(int i=0;i<maxXorr;i++) {
            if(tripletXorr[i]) cnt++;
        }
        return cnt;
    }
};