class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int cnt=0;
        for(int i=num1;i<=num2;i++) {
            string str=to_string(i);
            int len=str.length();
            for(int j=1;j<len-1;j++) {
                if((str[j]>str[j-1] && str[j]>str[j+1]) || (str[j]<str[j-1] && str[j]<str[j+1])) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};