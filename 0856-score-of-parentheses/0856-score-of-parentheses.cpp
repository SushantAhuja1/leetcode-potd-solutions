class Solution {
public:
    int scoreOfParentheses(string s) {
        if(s.empty()) return 0;
        int n=s.length();
        int counter=0;
        int start=0;
        int score=0;
        vector<string>chunks;
        for(int i=0;i<n;i++) {
            if(s[i]=='(') counter++;
            else counter--;
            if(counter==0) {
                string inner = s.substr(start+1,i-start-1);
                if(inner.empty()) score+=1;
                else {
                    int val=2*scoreOfParentheses(inner);
                    score+=val;
                }
                start=i+1;
            }
        }
        return score;
    }
};