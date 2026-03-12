class dsu {
public:
    vector<int> parent;
    int components;
    dsu(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        components = n;
    }
    int findParent(int x) {
        if (parent[x] == x) return x;
        return parent[x] = findParent(parent[x]);
    }
    bool unite(int x, int y) {
        int px = findParent(x);
        int py = findParent(y);
        if (px == py) return false;
        parent[px] = py;
        components--;
        return true;
    }
};

class Solution {
public:
    bool check(int mid, int n, int k, const vector<vector<int>>& edges) {
        dsu ds(n);
        
        // 1. Mandatory edges must be >= mid. If not, this 'mid' is impossible.
        for (const auto& e : edges) {
            if (e[3] == 1) {
                if (e[2] < mid) return false;
                ds.unite(e[0], e[1]);
            }
        }

        // 2. Use optional edges that already satisfy 'mid' without upgrades.
        for (const auto& e : edges) {
            if (e[3] == 0 && e[2] >= mid) {
                ds.unite(e[0], e[1]);
            }
        }

        // 3. Use upgrades only if needed to connect remaining components.
        int upgradesUsed = 0;
        for (const auto& e : edges) {
            if (e[3] == 0 && e[2] < mid && 2 * e[2] >= mid) {
                if (ds.unite(e[0], e[1])) {
                    upgradesUsed++;
                }
            }
        }

        return ds.components == 1 && upgradesUsed <= k;
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {
        // Essential check: Do mandatory edges form a cycle?
        dsu cycleCheck(n);
        for (const auto& e : edges) {
            if (e[3] == 1) {
                if (!cycleCheck.unite(e[0], e[1])) return -1;
            }
        }

        // Essential check: Is the graph even connectable?
        dsu connectCheck(n);
        for (const auto& e : edges) connectCheck.unite(e[0], e[1]);
        if (connectCheck.components > 1) return -1;

        int low = 0, high = 200000; // Max possible strength is 10^5 * 2
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(mid, n, k, edges)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};