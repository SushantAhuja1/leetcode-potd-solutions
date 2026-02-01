class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n=nums.size();
        // if(n==3) return accumulate(nums.begin(),nums.end(),0);
        int ans=nums[0];
        int firstIdx=min_element(nums.begin()+1,nums.end())-nums.begin();
        // cout<<"firstIdx: "<<firstIdx<<endl;
        ans+=nums[firstIdx];
        if(firstIdx==1) {
            int idx=min_element(nums.begin()+2,nums.end())-nums.begin();
            ans+=nums[idx];
            return ans;
        }
        int secondIdx=min_element(nums.begin()+firstIdx+1,nums.end())-nums.begin();
        if(secondIdx>=n) nums[secondIdx]=INT_MAX;
        int optionIdx=min_element(nums.begin()+1,nums.begin()+firstIdx)-nums.begin();
        // cout<<"secondIdx: "<<secondIdx<<endl;
        // cout<<"optionIdx: "<<optionIdx<<endl;
        ans+=min(nums[secondIdx],nums[optionIdx]);
        return ans;
    }
};