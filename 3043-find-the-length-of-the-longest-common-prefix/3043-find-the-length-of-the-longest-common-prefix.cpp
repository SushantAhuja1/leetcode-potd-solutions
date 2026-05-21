class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n=arr1.size();
        int ans=0;
        unordered_map<string,bool>mp;
        for(int i=0;i<n;i++) {
            int num=arr1[i];
            string str=to_string(num);
            int l=str.length();
            for(int j=0;j<l;j++) {
                string subStr=str.substr(0,j+1);
                mp[subStr]=true;
            }
        }
        int m=arr2.size();
        for(int i=0;i<m;i++) {
            int num=arr2[i];
            string str=to_string(num);
            int l=str.length();
            for(int j=0;j<l;j++) {
                string subStr=str.substr(0,j+1);
                if(mp.count(subStr)) {
                    ans=max(ans,j+1);
                }
            }
        }
        return ans;
    }
};