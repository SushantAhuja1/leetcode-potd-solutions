class Solution {
public:
    bool validDigit(int n, int x) {
        string str=to_string(n);
        int cntX=count(str.begin(),str.end(),x+'0');
        return cntX>=1 && str[0]!=(x+'0');
    }
};