class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size(),i=0,j=n-1;
        int leftToRight=1,rightToLeft=1;
        int maxi=INT_MIN;
        while(i<n && j>=0) {
            leftToRight=leftToRight*nums[i];
            rightToLeft=rightToLeft*nums[j];
            maxi=max({maxi,leftToRight,rightToLeft});
            if(leftToRight==0) {
                leftToRight=1;
            } 
            if(rightToLeft==0) {
                rightToLeft=1;
            }
            i++;
            j--;
        }
        return maxi;
    }
};