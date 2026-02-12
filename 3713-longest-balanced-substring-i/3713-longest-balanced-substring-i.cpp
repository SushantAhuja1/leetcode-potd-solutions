class Solution {
public:
    int n,maxL;
    vector<vector<int>>arr;
    int possible(vector<int>& temp) {
        int prev=-1;
        for(int i=0;i<26;i++) {
            if(temp[i]!=0) {
                if(prev==-1) {
                    prev=temp[i];
                    continue;
                } else if(temp[i]!=prev) return false;
            }
        }
        return true;
    }
    int longestBalanced(string s) {
        n=s.size();
        maxL=0;
        arr.resize(n,vector<int>(26,0));
        for(int i=0;i<n;i++) {
            char ch=s[i];
            int idx=ch-'a';
            arr[i][idx]++;
        }
        for(int r=0;r<n;r++) {
            vector<int>temp(26,0);
            for(int l=r;l>=0;l--) {
                for(int i=0;i<26;i++) {
                    temp[i]+=arr[l][i];
                }
                // cout<<"r : "<<r<<endl;
                // cout<<"l : "<<l<<endl;
                // cout<<"Printing temp : "<<endl;
                // for(auto &t:temp) cout<<t<<" ";
                // cout<<endl;
                if(possible(temp)) {
                    maxL=max(maxL,r-l+1);
                }
            }
        }
        return maxL;
    }
};