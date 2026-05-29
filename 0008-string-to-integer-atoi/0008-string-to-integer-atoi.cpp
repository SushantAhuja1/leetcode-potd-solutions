class Solution {
public:
    int myAtoi(string s) {
        int i=0,n=s.length();
        // if(s=="2147483648") {
        //     return 2147483647;
        // }
        // if(s=="-2147483649") {
        //     return -2147483648;
        // }
        while(s[i]==' ') {
            i++;
        }
        if(i>=n) return 0;
        int sign=1;
        if(s[i]=='-') {
            sign=-1;
            i++;
        } else if(s[i]=='+') {
            i++;
        }
        long long ans=0;
        bool maxFound=false;
        while(isdigit(s[i])) {
            ans = ans * 10 + (s[i] - '0');
            
            // If the value strictly exceeds INT_MAX, handle capping immediately
            if (ans > INT_MAX) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            i++;
        }
        return ans*sign;
    }
};