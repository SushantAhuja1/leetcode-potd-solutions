class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n == 1)
            return 0;
        vector<int> visited(n, 0);
        queue<int> q;
        q.push(0);
        visited[0] = 1;
        unordered_map<int, set<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[arr[i]].insert(i);
        }
        int cnt = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                int i = q.front();
                q.pop();
                if (i == n - 1)
                    return cnt;
                if (i + 1 < n && !visited[i + 1]) {
                    visited[i + 1] = 1;
                    q.push(i + 1);
                }
                if (i - 1 >= 0 && !visited[i - 1]) {
                    visited[i - 1] = 1;
                    q.push(i - 1);
                }
                for (auto& j : mp[arr[i]]) {
                    if (!visited[j]) {
                        visited[j] = 1;
                        q.push(j);
                    }
                }
                mp[arr[i]].clear();
            }
            cnt++;
        }
        return cnt;
    }
};