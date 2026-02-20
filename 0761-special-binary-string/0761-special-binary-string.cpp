class Solution {
public:
    string makeLargestSpecial(string s) {
        int count=0;
        int start=0;
        int n=s.length();
        string ans="";
        vector<string>chunks;
        for(int i=0;i<n;i++) {
            if(s[i]=='1') count++;
            else count--;
            if(count==0) {
                string inner = s.substr(start+1,i-start-1);
                string maximisedChunk = "1"+makeLargestSpecial(inner)+"0";
                chunks.push_back(maximisedChunk);
                start=i+1;
            }
        }
        sort(chunks.begin(),chunks.end(),greater<string>());
        for(int i=0;i<chunks.size();i++) {
            ans+=chunks[i];
        }
        return ans;
    }
};