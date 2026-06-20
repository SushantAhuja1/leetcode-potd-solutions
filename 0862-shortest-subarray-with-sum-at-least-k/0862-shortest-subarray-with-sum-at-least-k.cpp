class Solution {
public:
    #define ll long long
    int shortestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int>dq;
        vector<ll>cumulativeSum(n,0);
        int result=INT_MAX;
        int j=0;
        while(j<n) {
            if(j==0) {
                cumulativeSum[j]=nums[j];
            } else {
                cumulativeSum[j]=cumulativeSum[j-1]+nums[j];
            }
            if(cumulativeSum[j]>=k) {
                result=min(result,j+1);
            }
            while(!dq.empty() && cumulativeSum[j]-cumulativeSum[dq.front()]>=k) {
                result=min(result,j-dq.front());
                dq.pop_front();
            }
            while(!dq.empty() && cumulativeSum[j]<=cumulativeSum[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(j);
            j++;
        }
        return result>=INT_MAX?-1:result;
    }
};