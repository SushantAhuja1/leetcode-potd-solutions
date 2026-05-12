class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return (a[1]-a[0])>(b[1]-b[0]);
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(),tasks.end(),cmp);
        int initially=tasks[0][1],curr=initially,n=tasks.size();
        for(int i=0;i<n;i++) {
            int actual=tasks[i][0];
            int req=tasks[i][1];
            // cout<<"before processing : "<<endl;
            // cout<<"i : "<<i<<" , actual : "<<actual<<" , req : "<<req<<" , curr : "<<curr<<" , initially : "<<initially<<endl;
            if(curr>=req) {
                curr-=actual;
            } else {
                int diff=req-curr;
                initially+=diff;
                curr=req-actual;
            }
            // cout<<"after processing  : "<<endl;
            // cout<<"i : "<<i<<" , actual : "<<actual<<" , req : "<<req<<" , curr : "<<curr<<" , initially : "<<initially<<endl;
        }
        return initially;
    }
};