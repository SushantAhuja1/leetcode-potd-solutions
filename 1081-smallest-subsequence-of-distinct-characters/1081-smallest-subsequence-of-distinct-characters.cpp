class Solution {
public:
    string smallestSubsequence(string s) {
        unordered_map<char,int>lastIndex;
        int n=s.size();
        for(int i=0;i<n;i++) {
            lastIndex[s[i]]=i;
        }
        stack<char>st;
        unordered_set<char>seen;
        for(int i=0;i<n;i++) {
            char curr=s[i];
            if(seen.count(curr)) continue;
            if(st.empty() || curr>st.top() && (!seen.count(curr))) {
                st.push(s[i]);
                seen.insert(curr);
            }
            else {
                while(!st.empty() && lastIndex[st.top()]>i && st.top()>curr) {
                    seen.erase(st.top());
                    st.pop();
                }
                st.push(curr);
                seen.insert(curr);
            }
        }
        string ans="";
        while(!st.empty()) {
            char curr=st.top();
            st.pop();
            ans+=curr;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};