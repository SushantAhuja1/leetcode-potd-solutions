class Solution {
public:
    int minOperations(string s, int k) {
        int n=s.length();
        int startZeros=0;
        vector<int>operations(n+1,-1);
        for(int i=0;i<n;i++) {
            if(s[i]=='0') startZeros++;
        }
        if(startZeros==0) return 0;
        set<int>evenSet;
        set<int>oddSet;
        for(int count=0;count<=n;count++) {
            if(count%2==0) {
                evenSet.insert(count);
            } else {
                oddSet.insert(count);
            }
        }
        operations[startZeros]=0;
        queue<int>q;
        q.push(startZeros);
        if(startZeros%2==0) {
            evenSet.erase(startZeros);
        } else {
            oddSet.erase(startZeros);
        }
        while(!q.empty()) {
            int z=q.front();
            q.pop();
            int min_new_z=z+k-2*min(k,z);
            int max_new_z=z+k-2*max(0,k-n+z);
            set<int> &currSet = (min_new_z%2==0) ? evenSet : oddSet;
            auto it = currSet.lower_bound(min_new_z);
            while(it!=currSet.end() && *it<=max_new_z) {
                int newz = *it;
                if(operations[newz]==-1) {
                    operations[newz]=operations[z]+1;
                    if(newz==0) return operations[newz];
                    q.push(newz);
                }
                it = currSet.erase(it);
            }
        }
        return -1;
    }
};