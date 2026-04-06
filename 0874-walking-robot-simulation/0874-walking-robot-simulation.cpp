class Solution {
public:
    // directions -> {n,1},{e,2},{s,3},{w,4}
    set<pair<int, int>> st;
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        for (auto& obs : obstacles) {
            int x = obs[0], y = obs[1];
            st.insert({x, y});
        }
        int x = 0, y = 0, maxi = 0, n = commands.size(), currDir = 1;
        for (int i = 0; i < n; i++) {
            if (commands[i] > 0) {
                for (int step = 0; step < commands[i]; step++) {
                    int nextX = x, nextY = y;

                    // Determine the next coordinate based on direction
                    if (currDir == 1)
                        nextY++; // North
                    else if (currDir == 2)
                        nextX++; // East
                    else if (currDir == 3)
                        nextY--; // South
                    else if (currDir == 4)
                        nextX--; // West

                    // Check if the VERY NEXT step is an obstacle
                    if (st.find({nextX, nextY}) == st.end()) {
                        x = nextX;
                        y = nextY;
                        // Update maxi after every successful step
                        maxi = max(maxi, x * x + y * y);
                    } else {
                        // Hit an obstacle! Stop moving for this command.
                        break;
                    }
                }
            } else if (commands[i] == -2) {
                switch (currDir) {
                case 1:
                    currDir = 4;
                    break;
                case 2:
                    currDir = 1;
                    break;
                case 3:
                    currDir = 2;
                    break;
                case 4:
                    currDir = 3;
                    break;
                }
            } else if (commands[i] == -1) {
                switch (currDir) {
                case 1:
                    currDir = 2;
                    break;
                case 2:
                    currDir = 3;
                    break;
                case 3:
                    currDir = 4;
                    break;
                case 4:
                    currDir = 1;
                    break;
                }
            }
        }
        return maxi;
    }
};