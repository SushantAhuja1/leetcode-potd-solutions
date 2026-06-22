class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int b=1;
        int a=1;
        int l=2;
        int o=2;
        int n=1;
        unordered_map<char,int>mp;
        for(auto &i:text) {
            mp[i]++;
        }
        int bCnt=mp['b']/b;
        int aCnt=mp['a']/a;
        int lCnt=mp['l']/l;
        int oCnt=mp['o']/o;
        int nCnt=mp['n']/n;
        return min({bCnt,aCnt,lCnt,oCnt,nCnt});
    }
};