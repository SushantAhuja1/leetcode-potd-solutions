class Solution {
public:
    int smallestNumber(int n, int t) {
        for(int i=n;;i++) {
            int num=i;
            int p=1;
            while(num>0) {
                int d=num%10;
                p=p*d;
                num/=10;
            }
            if(p%t==0) return i;
        }
        return -1;
    }
};