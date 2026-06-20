class Solution {
public:
    vector<string> createGrid(int m, int n) {
        if(m==1 && n==1) return {"."};
        vector<string>ans;
        for(int i=0;i<m;i++) {
            string x(n,'.');
            if(i!=m-1) {
                x[1]='#';
            }
            ans.push_back(x);
        }
        return ans;
    }
};