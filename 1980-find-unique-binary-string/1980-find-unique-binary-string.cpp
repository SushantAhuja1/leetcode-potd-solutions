class Solution {
public:
    string getString(int curr,int n) {
        string ans="";
        if(curr==0) {
            return string(n,'0');
        }
        while(curr>0) {
            int d=curr%2;
            curr/=2;
            ans+=(d+'0');
        }   
        if(ans.size()<n) {
            int diff=n-ans.size();
            for(int i=1;i<=diff;i++) {
                ans+='0';
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums[0].length();
        int k=0;
        string str;
        for(int i=0;i<pow(2,n);i++) {
            int curr=i;
            str=getString(curr,n);
            if(k<nums.size() && str==nums[k]) {
                k++;
            } else {
                return str;
            }
        }
        return "";
    }
};