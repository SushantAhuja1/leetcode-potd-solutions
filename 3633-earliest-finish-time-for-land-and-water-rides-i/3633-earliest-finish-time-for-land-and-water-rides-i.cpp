class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n=landStartTime.size();
        int m=waterStartTime.size();
        int ans=1e9;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                int val1=landStartTime[i]+landDuration[i];
                int val2=waterStartTime[j]+waterDuration[j];
                ans=min(ans,max(val1, waterStartTime[j]) + waterDuration[j]);
                ans=min(ans,max(val2, landStartTime[i]) + landDuration[i]);
            }
        }
        return ans;
    }
};