class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> small(26, -1);
        vector<int> capital(26, -1);

        int n = word.size();

        for (int i = 0; i < n; i++) {
            if (word[i] >= 'a' && word[i] <= 'z') {
                small[word[i] - 'a'] = i; 
            } 
            else {
                int idx = word[i] - 'A';
                if (capital[idx] == -1) { 
                    capital[idx] = i;
                }
            }
        }

        int cnt = 0;

        for (int i = 0; i < 26; i++) {
            if (small[i] != -1 &&
                capital[i] != -1 &&
                small[i] < capital[i]) {
                cnt++;
            }
        }

        return cnt;
    }
};