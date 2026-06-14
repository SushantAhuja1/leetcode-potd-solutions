class Solution {
public:
    int n;
    unordered_map<int, vector<int>> adj;
    vector<int> color;
    bool isBipartite(vector<vector<int>>& graph) {
        n = graph.size();
        color.resize(n, -1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < graph[i].size(); j++) {
                adj[i].push_back(graph[i][j]);
                adj[graph[i][j]].push_back(i);
            }
        }
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                q.push({i, 0});
                color[i] = 0;
                while (!q.empty()) {
                    int node = q.front().first;
                    int c = q.front().second;
                    q.pop();
                    for (auto& nbr : adj[node]) {
                        if (color[nbr] == color[node])
                            return false;
                        else if (color[nbr] == -1) {
                            color[nbr] = !c;
                            q.push({nbr, !c});
                        } else {
                            continue;
                        }
                    }
                }
            }
        }

        return true;
    }
};