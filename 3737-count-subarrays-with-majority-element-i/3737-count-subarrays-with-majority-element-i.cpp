class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        // int n=nums.size(),i=0,j=0,cnt=0;
        // unordered_map<int,int>mp;
        // while(j<n) {
        //     mp[nums[j]]++;
        //     while(2*mp[target]>(j-i+1)) {
        //         cout<<"i : "<<i<<" j : "<<j<<endl;
        //         cnt+=(j-i+1);
        //         mp[nums[i]]--;
        //         if(mp[nums[i]]==0) {
        //             mp.erase(nums[i]);
        //         }
        //         i++;
        //     }
        //     j++;
        // }
        // return cnt;
        int n=nums.size(),cnt=0;
        for(int i=0;i<n;i++) {
            unordered_map<int,int>mp;
            for(int len=1;len<=n-i;len++) {
                mp[nums[i+len-1]]++;
                int freqOfTarget=mp[target];
                if(2*freqOfTarget>len) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};