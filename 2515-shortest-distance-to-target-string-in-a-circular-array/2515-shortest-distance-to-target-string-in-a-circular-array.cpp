class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n=words.size();
        bool found=false;
        for(auto &i:words) {
            if(i==target) {
                found=true;
                break;
            }
        }
        if(!found) return -1;
        int ans=1e9;
        int cnt=1;
        int i=startIndex;
        int jumps=0;
        while(cnt!=n) {
            if(words[i]==target) {
                ans=min(ans,jumps);
            }
            i=(i+1)%n;
            cnt++;
            jumps++;
        }
        i=startIndex;
        cnt=1;
        jumps=0;
        while(cnt!=n) {
            if(words[i]==target) {
                ans=min(ans,jumps);
            }
            i=(i-1+n)%n;
            cnt++;
            jumps++;
        }
        return ans;
    }
};