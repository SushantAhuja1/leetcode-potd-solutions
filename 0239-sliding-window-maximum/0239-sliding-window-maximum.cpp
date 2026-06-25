class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        int i=0,j=0,n=nums.size();
        deque<int>dq;
        while(j<n) {
            int curr=nums[j];
            if(dq.empty()) {
                dq.push_back(j);
            }
            else {
                while(!dq.empty() && j-dq.front()>=k) dq.pop_front();
                while(!dq.empty() && curr>nums[dq.back()]) dq.pop_back();
                dq.push_back(j);
            }
            if(j-i+1==k) {
                ans.push_back(nums[dq.front()]);
                i++;
            }
            j++;
        }
        return ans;
    }
};