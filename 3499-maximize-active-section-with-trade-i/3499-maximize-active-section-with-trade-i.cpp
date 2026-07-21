class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n=s.length();
        int ans=0;
        int count1=count(s.begin(),s.end(),'1');
        int cnt=0;
        vector<int>arr;
        for(int i=0;i<n;) {
            if(s[i]=='1') {
                cnt=0;
                i++;
            } else {
                int j=i;
                while(j<n && s[j]=='0') {
                    cnt++;
                    j++;
                }
                arr.push_back(cnt);
                i=j;
            }
        }
        int sz=arr.size();
        for(int i=1;i<sz;i++) {
            int curr=arr[i]+arr[i-1];
            ans=max(ans,curr);
        }
        return ans+count1;
    }
};