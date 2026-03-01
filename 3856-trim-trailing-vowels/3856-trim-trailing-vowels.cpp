class Solution {
public:
    bool isVowel(char ch) {
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u') return true;
        return false;
    }
    string trimTrailingVowels(string s) {
        int n=s.length();
        while(!s.empty() && isVowel(s.back())) {
            s.pop_back();
        }
        return s;
    }
};