class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n=moves.length();
        int cntL=count(moves.begin(),moves.end(),'L');
        int cntR=count(moves.begin(),moves.end(),'R');
        int cnt_=n-cntL-cntR;
        if(cntL>=cntR) {
            return cntL-cntR+cnt_;
        }
        return cntR-cntL+cnt_;
    }
};