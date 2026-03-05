class Solution {
public:
    int removeAlmostEqualCharacters(string word) {
        int cnt=0,n=word.length();
        for(int i=0;i<n-1;i++) {
            if(abs(word[i]-word[i+1])==1 || word[i]==word[i+1]) {
                cnt++;
                i++;
            }
        }
        return cnt;
    }
};