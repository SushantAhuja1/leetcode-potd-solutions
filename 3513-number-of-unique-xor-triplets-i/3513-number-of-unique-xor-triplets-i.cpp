class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        int x=log2(n)+1;
        if(n>=3) return pow(2,x);
        else if(n==2) return 2;
        return 1;
    }
};

// 2^x>n
// x=logn base 2
// 