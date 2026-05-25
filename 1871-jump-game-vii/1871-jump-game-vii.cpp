class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.length();
        vector<bool>visited(n,0);
        visited[0]=1;
        queue<int>q;
        q.push(0);
        int farthest=0;
        while(!q.empty()) {
            int idx=q.front();
            q.pop();
            if(idx==n-1) return true;
            int start=max(farthest,idx+minJump);
            int end=min(n-1,idx+maxJump);
            for(int i=start;i<=end;i++) {
                if(!visited[i] && s[i]=='0') {
                    visited[i]=1;
                    q.push(i);
                }
            }
            farthest=end+1;
        }
        return false;
    }
};