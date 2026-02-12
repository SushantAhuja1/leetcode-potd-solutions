class Solution {
public:
    long long countPairs(vector<string>& words) {
        long long ans = 0;
        // Map to store the count of each normalized string
        unordered_map<string, int> counts;

        for (const string& s : words) {
            if (s.empty()) continue;

            // Calculate shift needed to make the first character 'a'
            int shift = s[0] - 'a';
            string normalized = s; 
            
            for (int i = 0; i < normalized.length(); i++) {
                // Shift backward by 'shift' amount
                // We add 26 before modulo to handle negative results
                normalized[i] = (normalized[i] - 'a' - shift + 26) % 26 + 'a';
            }

            // If we've seen this normalized version 'k' times before,
            // the current word forms 'k' new pairs with them.
            ans += counts[normalized];
            
            // Increment the count for this normalized group
            counts[normalized]++;
        }

        return ans;
    }
};