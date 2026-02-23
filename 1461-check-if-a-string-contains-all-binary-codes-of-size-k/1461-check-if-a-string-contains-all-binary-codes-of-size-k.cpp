class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string>st;
        int n=s.length();
        for(int i=0;i<=n-k;i++) {
            string curr=s.substr(i,k);
            st.insert(curr);
        }
        return (int)st.size()==pow(2,k);
    }
};