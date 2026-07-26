class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<>>pq;
        int cntNeg=0;
        for(auto &i:nums) {
            if(pq.size()<3) {
                pq.push(i);
            } else {
                if(i>pq.top()) {
                    pq.pop();
                    pq.push(i);
                }
            }
            if(i<0) {
                cntNeg++;
            }
        }
        int prod=1;
        int ans=INT_MIN;
        while(!pq.empty()) {
            prod*=pq.top();
            pq.pop();
        }
        ans=max(ans,prod);
        prod=1; 
        sort(nums.begin(),nums.end());
        if(cntNeg>1) {
            prod=prod*nums[0];
            prod=prod*nums[1];
            prod=prod*nums.back();
            ans=max(ans,prod);
        }
        return ans;
    }
};