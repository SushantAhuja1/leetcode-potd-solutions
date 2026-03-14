class Solution {
public:
    set<string>st;
    void solve(int n,string str,char prev) {
        if(str.length()==n) {
            if(!st.count(str)) {
                st.insert(str);
            }
            return;
        }
        for(char ch='a';ch<='c';ch++) {
            if(ch==prev) continue;
            else {
                str+=ch;
                solve(n,str,ch);
                str.pop_back();
            }
        }
    }
    string getHappyString(int n, int k) {
        solve(n,"",'!');
        int sz=st.size();
        if(k>sz) return "";
        int cnt=0;
        for(auto &i:st) {
            cnt++;
            if(cnt==k) return i;
        }
        return "";
    }
};