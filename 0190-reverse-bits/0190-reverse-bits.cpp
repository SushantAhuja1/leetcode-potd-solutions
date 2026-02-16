class Solution {
public:
    int reverseBits(int n) {
        bitset<32>b(n);
        bitset<32>r(n);
        for(int i=0;i<32;i++) {
            r[i]=b[32-i-1];
        }
        int ans=0;
        for(int i=0;i<32;i++) {
            ans=ans+r[32-i-1]*pow(2,32-1-i);
        }
        return ans;
    }
};