class Solution {
public:
    int minimumOR(vector<vector<int>>& grid) {
        int ans=(1<<30)-1;
        for(int bit=29;bit>=0;bit--) {
            int test_ans=ans^(1<<bit);
            bool possible=true;
            for(int i=0;i<grid.size();i++) {
                bool row_possible=false;
                for(int j=0;j<grid[i].size();j++) {
                    if((grid[i][j]|test_ans) == test_ans) {
                        row_possible = true;
                        break;
                    }
                }
                if(!row_possible) {
                    possible=false;
                    break;
                }
            }
            if(possible) {
                ans=test_ans;
            }
        }
        return ans;
    }
};