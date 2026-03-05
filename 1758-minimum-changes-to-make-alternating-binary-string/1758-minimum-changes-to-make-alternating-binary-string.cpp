class Solution {
public:
    int n;
    int minOperations(string s) {
        n=s.length();
        int oneZero=0;
        int zeroOne=0;

        //101010 -> even=0,odd=1
        //010101 -> even=1,odd=0
        for(int i=0;i<n;i++) {
            if(i%2==0 && s[i]!='0') oneZero++;
            else if(i%2==1 && s[i]!='1') oneZero++;
            else if(i%2==0 && s[i]!='1') zeroOne++;
            else if(i%2==1 && s[i]!='0') zeroOne++;
        }
        return min(oneZero,zeroOne);
    }
};