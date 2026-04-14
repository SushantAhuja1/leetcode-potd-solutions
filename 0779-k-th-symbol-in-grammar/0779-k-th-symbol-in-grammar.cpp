class Solution {
public:
    int dfs(int n,int k,int root) {
        if(n==1) return root;
        int total=pow(2,n-1);
        if(k>(total/2)) {
            int nextRoot=(root==0)?1:0;
            return dfs(n-1,k-(total/2),nextRoot);
        } else {
            int nextRoot=(root==0)?0:1;
            return dfs(n-1,k,nextRoot);
        }
    }
    int kthGrammar(int n, int k) {
        return dfs(n,k,0);
    }
};