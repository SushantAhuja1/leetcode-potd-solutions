class Solution {
public:
    // vector<int>squares;
    // int getClosestSq(int x) {
    //     int low=0,high=squares.size()-1,ans=high;
    //     while(low<=high) {
    //         int mid=low+(high-low)/2;
    //         if(mid*mid==x) {
    //             return mid*mid;
    //         } else if(mid*mid>x) {
    //             high=mid-1;
    //         } else {
    //             ans=mid*mid;
    //             low=mid+1;
    //         }
    //     }
    //     return ans;
    // }
    int t[100001];
    bool solve(int n) {
        if(n==0) return false;
        if(t[n]!=-1) return t[n];
        // cout<<"closestSq : "<<closestSq<<endl;
        for(int i=1;i<=317;i++) {
            if(i*i<=n) {
                if(!solve(n-i*i)) {
                    return t[n]=true;
                }   
            } else {
                break;
            }
        }
        return t[n]=false;
    }
    bool winnerSquareGame(int n) {
        // for(int i=1;i<=317;i++) {
        //     squares.push_back(i*i);
        // }
        memset(t,-1,sizeof(t));
        bool res=solve(n); 
        return res;
    }
}; 