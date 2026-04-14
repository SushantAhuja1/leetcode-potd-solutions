class Solution {
public:
    #define ll long long
    int n,m;
    vector<int>f;
    vector<vector<ll>>t;
    ll solve(vector<int>& robot, vector<vector<int>>& factory, int i, int j) {
        //all robots are processed
        if(i>=n) {
            return 0;
        } 
        //if all the factories are processed
        if(j>=f.size()) {
            return 1e18;
        }
        if(t[i][j]!=-1) return t[i][j];
        ll skip=solve(robot,factory,i,j+1);
        ll take=abs(robot[i]-f[j])+solve(robot,factory,i+1,j+1);
        return t[i][j]=min(skip,take);
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        n=robot.size();
        m=factory.size();
        sort(factory.begin(),factory.end());
        sort(robot.begin(),robot.end());
        for(int i=0;i<m;i++) {
            int t=factory[i][1];
            for(int j=0;j<t;j++) {
                f.push_back(factory[i][0]);
            }
        }
        t.resize(n+1,vector<ll>(f.size()+1,-1ll));
        ll ans=solve(robot,factory,0,0);
        return ans;
    }
};

// 2 2 6 6 -> factory j
// 0 4 6 -> robot i