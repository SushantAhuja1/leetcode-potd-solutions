class Solution {
public:
    int n;
    unordered_map<int,int>mp;
    int ans=1e9;
    int minMirrorPairDistance(vector<int>& nums) {
        n=nums.size();
        for(int i=0;i<n;i++) {
            int currNum=nums[i];
            string currStr=to_string(currNum);
            string revStr=currStr;
            reverse(revStr.begin(),revStr.end());
            int revNum=stoi(revStr);
            if(mp.count(currNum)) {
                ans=min(ans,i-mp[currNum]);
            }
            mp[revNum]=i;
        }
        return ans>=1e9?-1:ans;
    }
};