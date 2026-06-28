class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n=arr.size();
        vector<int>nums;
        for(auto &i:arr) {
            nums.push_back(i);
        }
        sort(nums.begin(),nums.end());
        int cnt=0;
        //first-sort-the-array
        if(arr!=nums) {
            cnt++;
            sort(arr.begin(),arr.end());
        }
        //check-for-first-element-equal-to-1
        if(arr[0]!=1) {
            cnt++;
            arr[0]=1;
        }
        for(int i=1;i<n;i++) {
            if(arr[i]-arr[i-1]<=1) {
                continue;
            } else {
                arr[i]=arr[i-1]+1;
                cnt++;
            }
        }
        return arr.back();
    }
};

//2,2,1,2,1
//1,1,2,2,2

//100,1,1000
//1,100,1000
//1,2,3