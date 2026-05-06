class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();
        int n = boxGrid[0].size();
        vector<vector<char>> box(n, vector<char>(m, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                box[j][i] = boxGrid[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            reverse(box[i].begin(), box[i].end());
        }
        for (int col = 0; col < m; col++) {
            for (int row = n - 1; row >= 0; row--) {
                if (box[row][col] == '#' || box[row][col] == '*') {
                    continue;
                } else {
                    // if-it-is-empty-cell
                    int firstStone = -1, firstObs = -1;
                    int currRow = row;
                    while (currRow >= 0) {
                        if (box[currRow][col] == '#' && firstStone == -1) {
                            firstStone = currRow;
                            break;
                        }
                        currRow--;
                    }
                    currRow = row;
                    while (currRow >= 0) {
                        if (box[currRow][col] == '*' && firstObs == -1) {
                            firstObs = currRow;
                            break;
                        }
                        currRow--;
                    }
                    if (firstStone != -1 &&
                        (firstObs == -1 || firstStone > firstObs)) {
                        swap(box[row][col], box[firstStone][col]);
                    }
                }
            }
        }
        return box;
    }
};