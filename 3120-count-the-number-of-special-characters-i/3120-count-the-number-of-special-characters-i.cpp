class Solution {
public:
    int numberOfSpecialChars(string word) {
        int cnt=0;
        char ch='a';
        char ch1='A';
        unordered_map<char,int>st;
        for(auto &i:word) {
            st[i]++;
        }
        for(int i=0;i<26;i++) {
            if(st.count(ch+i) && st.count(ch1+i)) {
                cnt++;
            }
        }
        return cnt;
    }
};