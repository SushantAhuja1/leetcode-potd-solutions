class Solution {
public:
    int binaryGap(int n) {
        bitset<32>b(n);
        int last=-1,maxi=0;
        for(int i=31;i>=0;i--) {
            if(b[i]==1) {
                if(last==-1) last=i;
                else {
                    int diff=last-i;
                    maxi=max(maxi,diff);
                    last=i;
                }
            }
        }
        return maxi;
    }
};