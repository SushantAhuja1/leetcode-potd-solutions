class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prev=-1;
        while(n>0) {
            int curr=n%2;
            if(curr==prev) return false;
            n/=2;
            prev=curr;
        }
        return true;
    }
};