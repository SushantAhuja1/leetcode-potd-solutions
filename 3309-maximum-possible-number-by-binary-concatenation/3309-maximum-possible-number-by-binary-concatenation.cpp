class Solution {
public:
    int maxGoodNumber(vector<int>& nums) {
        //3 factorial -> 6 combinations -> getAll
        unordered_map<int,int>bits;
        for(int i=1;i<=127;i++) {
            int numberOfBits=log2(i)+1;
            bits[i]=numberOfBits;
        }
        int ans = 0;
        sort(nums.begin(),nums.end());
        do {
            int val=0;
            for(int i=0;i<3;i++) {
                val=val*pow(2,bits[nums[i]])+nums[i];
            }
            ans=max(ans,val);
        } while(next_permutation(nums.begin(),nums.end()));
        return ans;
    }
};