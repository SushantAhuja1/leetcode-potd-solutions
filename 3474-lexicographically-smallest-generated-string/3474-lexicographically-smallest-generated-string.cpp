class Solution {
public:
    int n, m;
    vector<char> word;
    string generateString(string str1, string str2) {
        n = str1.length();
        m = str2.length();
        word.resize(n + m - 1, '?');
        for (int i = 0; i < n; i++) {
            // if str1[i]=='T'
            if (str1[i] == 'T') {
                int k = 0;
                for (int idx = i; idx <= i + m - 1; idx++) {
                    if (word[idx] == '?') {
                        word[idx] = str2[k];
                        k++;
                    } else if (word[idx] == str2[k]) {
                        k++;
                    } else {
                        return "";
                    }
                }
            }
        }
        // ... (Keep your Pass 1 'T' logic exactly as it is) ...

        // 1. Remember original '?' positions and optimistically fill with 'a'
        vector<bool> is_free(word.size(), false);
        for (int i = 0; i < word.size(); i++) {
            if (word[i] == '?') {
                is_free[i] = true;
                word[i] = 'a'; // Optimistically aim for the smallest string
            }
        }

        // 2. Pass 2: Check and fix 'F' conditions
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'F') {
                // Check if the current window exactly matches str2
                bool is_match = true;
                for (int k = 0; k < m; k++) {
                    if (word[i + k] != str2[k]) {
                        is_match = false;
                        break;
                    }
                }

                // If it exactly matches, we have a violation! We MUST change a
                // character.
                if (is_match) {
                    bool fixed = false;
                    // Find the RIGHTMOST character in this window that we are
                    // allowed to change
                    for (int k = m - 1; k >= 0; k--) {
                        int idx = i + k;
                        if (is_free[idx]) {
                            // Since it matched, word[idx] is currently 'a' and
                            // str2[k] is 'a'. Changing it to 'b' cleanly breaks
                            // the match.
                            word[idx] = 'b';
                            fixed = true;
                            break;
                        }
                    }

                    // If we couldn't find any original '?' to change, it's a
                    // contradiction
                    if (!fixed) {
                        return "";
                    }
                }
            }
        }

        // 3. Build the final string
        string ans = "";
        for (char& ch : word) {
            ans += ch;
        }
        return ans;
    }
};