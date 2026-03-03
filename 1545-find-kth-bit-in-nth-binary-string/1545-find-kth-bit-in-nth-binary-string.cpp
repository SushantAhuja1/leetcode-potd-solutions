class Solution {
public:
    vector<string>ans;
    string generate(string prev) {
        string newPrev=prev;
        string x="";
        for(auto &ele:newPrev) {
            x+=to_string(!(ele-'0'));
        }
        reverse(x.begin(),x.end());
        string curr=prev+"1"+x;
        return curr;
    }
    char findKthBit(int n, int k) {
        ans.push_back("0");
        for(int i=2;i<=n;i++) {
            ans.push_back(generate(ans.back()));
        }
        string res=ans.back();
        return res[k-1];
    }
}; 