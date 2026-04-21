class Solution {
public:
    int n;
    vector<int> parent, rank;
    unordered_map<int, vector<int>> mp;
    
    int findParent(int x) {
        if (x == parent[x])
            return x;
        return parent[x] = findParent(parent[x]);
    }
    
    void unite(int a, int b) {
        int pa = findParent(a);
        int pb = findParent(b);
        if (pa == pb)
            return;
        if (rank[pa] < rank[pb]) {
            parent[pa] = pb;
        } else if (rank[pa] > rank[pb]) {
            parent[pb] = pa;
        } else {
            parent[pb] = pa;
            rank[pa]++;
        }
    }
    
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        n = source.size();
        parent.resize(n, 0);
        iota(parent.begin(), parent.end(), 0);
        rank.resize(n, 1);
        
        int noSwapsCnt = 0;
        if (allowedSwaps.size() == 0) {
            for (int i = 0; i < n; i++) {
                if (source[i] != target[i]) {
                    noSwapsCnt++;
                }
            }
            return noSwapsCnt;
        }
        
        sort(allowedSwaps.begin(), allowedSwaps.end());
        for (auto& swap : allowedSwaps) {
            int x = swap[0], y = swap[1];
            unite(x, y);
        }
        
        for (int i = 0; i < n; i++) {
            mp[findParent(i)].push_back(i);
        }
        
        int cnt = 0;
        for (auto& i : mp) {
            unordered_map<int, int> temp;
            int sz = i.second.size();
            for (int j = 0; j < sz; j++) {
                temp[source[i.second[j]]]++;
                temp[target[i.second[j]]]--;
            }
            for (auto& pair : temp) {
                if (pair.second > 0) {
                    cnt += pair.second;
                }
            }
        }
        
        return cnt;
    }
};