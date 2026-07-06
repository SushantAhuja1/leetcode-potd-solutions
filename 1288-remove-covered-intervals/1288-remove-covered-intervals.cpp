class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        if(a[0]!=b[0]) return a[0]<b[0];
        return a[1]>b[1];
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        int cnt=0;
        sort(intervals.begin(),intervals.end(),cmp);
        for(int i=1;i<n;i++) {
            int prevStart=intervals[i-1][0];
            int prevEnd=intervals[i-1][1];
            int currStart=intervals[i][0];
            int currEnd=intervals[i][1];
            if(prevStart<=currStart && currEnd<=prevEnd) {
                cnt++;
                intervals[i][0]=prevStart;
                intervals[i][1]=prevEnd;
            } else {
                continue;
            }
        }
        return n-cnt;
    }
};

// [1,2],[1,4],[3,4]
// [1,2],[1,4],