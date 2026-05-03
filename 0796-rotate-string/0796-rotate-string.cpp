class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.length();
        for(int i=0;i<n;i++) {
            char ch=s[0];
            string newS=s.substr(1);
            newS+=ch;
            if(newS==goal) return true;
            s=newS;
        }
        return false;
    }
};

// abcde
// bcdea
// cdeab
// deabc 
// eabcd
// abcde