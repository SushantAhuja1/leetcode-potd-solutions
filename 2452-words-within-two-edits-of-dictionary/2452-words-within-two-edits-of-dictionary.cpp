class Solution {
public:
    int n,m,l;
    vector<string>ans;
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        n=queries.size();
        m=dictionary.size();
        l=queries[0].size();
        for(int i=0;i<n;i++) {
            string currString=queries[i];
            for(int j=0;j<m;j++) {
                string currTarget=dictionary[j];
                int cntChanges=0;
                for(int k=0;k<l;k++) {
                    if(currString[k]==currTarget[k]) continue;
                    else {
                        cntChanges++;
                    }
                }
                if(cntChanges<=2) {
                    ans.push_back(currString);
                    break;
                }
            }
        }
        return ans;
    }
};