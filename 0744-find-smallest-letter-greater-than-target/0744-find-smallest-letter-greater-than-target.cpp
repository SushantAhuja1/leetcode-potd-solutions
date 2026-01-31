class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n=letters.size();
        int ubIndex=upper_bound(letters.begin(),letters.end(),target)-letters.begin();
        if(ubIndex==n) return letters[0];
        return letters[ubIndex];
    }
};