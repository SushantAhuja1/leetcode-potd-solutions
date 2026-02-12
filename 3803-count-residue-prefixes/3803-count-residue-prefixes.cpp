class Solution {
public:
    int residuePrefixes(string s) {
        int n=s.length(),cnt=0;
        for(int i=0;i<n;i++) {
            string prefixStr = s.substr(0,i-0+1);
            unordered_set<char>st;
            for(auto &ch:prefixStr) {
                st.insert(ch);
            }
            if((int)st.size()==(i-0+1)%3) {
                cnt++;
            }
        }
        return cnt;
    }
};