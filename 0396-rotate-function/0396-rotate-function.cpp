class Solution {
public:
    int sum=0;
    int n;
    int initial=0;
    vector<int>t;
    int solve(vector<int>& nums,int k) {
        if(k==0) return initial;
        if(t[k]!=-1) return t[k];
        return t[k]=solve(nums,k-1)+sum-n*nums[n-k];
    }
    int maxRotateFunction(vector<int>& nums) {
        sum=accumulate(nums.begin(),nums.end(),0);
        n=nums.size();
        for(int i=0;i<n;i++) {
            initial+=(i*nums[i]);
        }
        t.resize(n+1,-1);
        int val=INT_MIN;
        for(int k=0;k<n;k++) {
            val=max(val,solve(nums,k));
        }
        return val;
    }
};
// (0+3)%4 => 3 0->3
// (1+3)%4 => 0 1->0
// (2+3)%4 => 1 2->1
// (3+3)%4 => 2 3->2


// Sum = 15
// F(0) = 25
// [4,3,2,6] -> 0*4 + 1*3 + 2*2 + 3*6
// F(1) = 16
// [6,4,3,2] -> 0*6 + 1*4 + 2*3 + 3*2
// 16 = 25+15-4*6 = 25-9 = 16