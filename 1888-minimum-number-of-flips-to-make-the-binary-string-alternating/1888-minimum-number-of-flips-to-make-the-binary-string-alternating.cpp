class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        s = s + s;

        int f1 = 0, f2 = 0;
        int ans = 1e9;

        for(int i = 0; i < 2*n; i++) {

            char p1 = (i % 2 ? '1' : '0'); // pattern 010101...
            char p2 = (i % 2 ? '0' : '1'); // pattern 101010...

            if(s[i] != p1) f1++;
            if(s[i] != p2) f2++;

            if(i >= n) {
                char prev1 = ((i-n) % 2 ? '1' : '0');
                char prev2 = ((i-n) % 2 ? '0' : '1');

                if(s[i-n] != prev1) f1--;
                if(s[i-n] != prev2) f2--;
            }

            if(i >= n-1)
                ans = min(ans, min(f1, f2));
        }

        return ans;
    }
};