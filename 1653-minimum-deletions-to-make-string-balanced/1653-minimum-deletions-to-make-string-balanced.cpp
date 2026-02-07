class Solution {
public:
    int minimumDeletions(string s) {
        int cnt_b=0,deletions=0;
        for(auto &c:s) {
            if(c=='b') cnt_b++;
            else {
                deletions=min(1+deletions,cnt_b);
            }
        }
        return deletions;
    }
};