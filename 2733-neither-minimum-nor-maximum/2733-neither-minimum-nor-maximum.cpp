class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        int n = nums.size() ;
        int maxi = INT_MIN ;
        int mini = INT_MAX ;
        for(int i = 0 ; i < n ; i++){
            maxi = max(maxi , nums[i]) ;
            mini = min(mini , nums[i]) ;
        }
        // Now traverse the array again 
        for(int i = 0 ; i < n ; i++){
            if(nums[i] != mini && nums[i] != maxi){
                return nums[i] ;
            }
        }
        // If we have traversed the entire vector and there are only 2 elements maxi and mini no other element  then
        return -1 ;   
    }
};