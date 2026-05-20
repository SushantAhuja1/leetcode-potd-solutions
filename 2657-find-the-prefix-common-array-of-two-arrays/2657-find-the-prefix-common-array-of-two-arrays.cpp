class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int>ans(n);
        for(int i=0;i<n;i++) {
            vector<int>a1,b1;
            for(int j=0;j<=i;j++) {
                a1.push_back(A[j]);
                b1.push_back(B[j]);
            }
            int cnt=0;
            unordered_map<int,int>m1,m2;
            for(auto &j:a1) m1[j]++;
            for(auto &j:b1) m2[j]++;
            for(auto &j:m1) {
                int f1=j.second;
                int f2=m2[j.first];
                if(f1==f2) {
                    cnt+=f1;
                }
            }
            ans[i]=cnt;
        }
        return ans;
    }
};