class Solution {
public:
    #define ll long long
    long long sumAndMultiply(int n) {
        ll num=0;
        ll sum=0;
        ll mul=1;
        while(n>0) {
            int d=n%10;
            if(d!=0) {
                num=num+d*mul;
                sum+=d;
                mul*=10;
            }
            n/=10;
        }
        return num*sum;
    }
};