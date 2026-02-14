class Solution {
public:
    int total;
    double t[101][101];
    double solve(int i,int j) {
        if(i<0 || j<0 || i<j) return 0.0;
        if(i==0 && j==0) return total;
        if(t[i][j]!=-1.0) return t[i][j];
        double left_up=(solve(i-1,j-1)-1)/2.0;
        double right_up=(solve(i-1,j)-1)/2.0;
        if(left_up<0) left_up=0.0;
        if(right_up<0) right_up=0.0;
        return t[i][j]=left_up+right_up;
    }
    double solveTab(int query_row,int query_glass) {
        for(int i=0;i<=query_row;i++) {
            for(int j=0;j<=query_glass;j++) {
                if(j>i || i<0 || j<0) {
                    t[i][j]=0.0;
                }
                else if(i==0 && j==0) {
                    t[i][j]=total;
                }
                else {
                    double left_up=(i>0 && j>0)?(t[i-1][j-1]-1)/2.0:0.0;
                    double right_up=(i>0)?(t[i-1][j]-1)/2.0:0.0;
                    if(left_up<0) left_up=0.0;
                    if(right_up<0) right_up=0.0;
                    t[i][j]=left_up+right_up;
                }
            }
        }
        return t[query_row][query_glass];
    }
    double champagneTower(int poured, int query_row, int query_glass) {
        total=poured;
        for(int i=0;i<101;i++) {
            for(int j=0;j<101;j++) {
                t[i][j]=0;
            }
        }
        double ans=solveTab(query_row,query_glass);
        return min(1.0,ans);
    }
};