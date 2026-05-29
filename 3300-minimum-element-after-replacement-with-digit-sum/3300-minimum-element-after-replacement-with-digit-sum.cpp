class Solution {
public:
    int minElement(vector<int>& nums) {
        int n=nums.size();
        int miniEle=1e9;
        for(int i=0;i<n;i++) {
            int sum=0;
            int num=nums[i];
            while(num>0) {
                int d=num%10;
                num/=10;
                sum+=d;
            }
            miniEle=min(miniEle,sum);
        }
        return miniEle;
    }
};