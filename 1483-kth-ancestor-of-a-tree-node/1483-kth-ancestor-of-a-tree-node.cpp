class TreeAncestor {
public:
    int cols, rows;
    vector<vector<int>> up;
    unordered_map<int, vector<int>> adj;
    TreeAncestor(int n, vector<int>& parent) {
        cols = log2(n) + 1;
        rows = n;
        up.resize(rows, vector<int>(cols, -1));
        for (int i = 0; i < n; i++) {
            up[i][0] = parent[i];
        }
        for (int i = 0; i < n; i++) {
            int node = i;
            int p = parent[i];
            if (p == -1)
                continue;
            else {
                adj[node].push_back(p);
                adj[p].push_back(node);
            }
        }
        for (int j = 1; j < cols; j++) {
            for (int u = 0; u < n; u++) {
                if (up[u][j - 1] != -1) {
                    up[u][j] = up[up[u][j - 1]][j - 1];
                }

                else {
                    up[u][j] = -1;
                }
            }
        }
    }

    int getKthAncestor(int node, int k) {
        for (int j = 0; j < cols && node != -1; j++) {
            if (k & (1 << j))
                node = up[node][j];
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */