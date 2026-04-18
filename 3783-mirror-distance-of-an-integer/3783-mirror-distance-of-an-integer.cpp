class Solution {
public:
    int mirrorDistance(int n) {
        string str=to_string(n);
        reverse(str.begin(),str.end());
        int m=stoi(str);
        return abs(n-m);
    }
};