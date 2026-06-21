class Solution {
public:
    int maxDistance(string moves) {
        int n=moves.length();
        int cntU=count(moves.begin(),moves.end(),'U');
        int cntD=count(moves.begin(),moves.end(),'D');
        int cntL=count(moves.begin(),moves.end(),'L');
        int cntR=count(moves.begin(),moves.end(),'R');
        int cnt_=count(moves.begin(),moves.end(),'_');
        int maxi=max({cntU,cntD,cntL,cntR});
        if(maxi==cntU) {
            cntU+=cnt_;
        } else if(maxi==cntD) {
            cntD+=cnt_;
        } else if(maxi==cntL) {
            cntL+=cnt_;
        } else {
            cntR+=cnt_;
        }
        int dist=0;
        dist+=abs(cntU-cntD);
        dist+=abs(cntR-cntL);
        return dist;
    }
};

// L L D L 
// -3,-1