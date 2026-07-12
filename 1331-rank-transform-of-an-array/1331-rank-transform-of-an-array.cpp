class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        if(n==0) return {};
        vector<int>ans,nums;
        for(int i=0;i<n;i++) {
            nums.push_back(arr[i]);
        }
        sort(nums.begin(),nums.end());
        unordered_map<int,int>eleToRank;
        int rank=1,ele=nums[0];
        for(int i=0;i<n;i++) {
            int curr=nums[i];
            if(curr==ele) {
                eleToRank[curr]=rank;
            } else {
                rank++;
                ele=curr;
                eleToRank[curr]=rank;
            }
        }
        for(auto &i:arr) {
            ans.push_back(eleToRank[i]);
        }
        return ans;
    }
};