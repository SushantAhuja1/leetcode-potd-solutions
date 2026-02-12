#include <vector>
#include <string>
#include <algorithm>
#include <cstring> // For memset

using namespace std;

class Solution {
    struct Node {
        int arr[26];
        int lazy[26];
        int maxFreq;
        int distinctCount;
        int lazyDistinct;
        
        // Constructor to reset values
        Node() {
            memset(arr, 0, sizeof(arr));
            memset(lazy, 0, sizeof(lazy));
            maxFreq = 0;
            distinctCount = 0;
            lazyDistinct = 0;
        }
    };
    
    vector<Node> tree;
    int n;

public:
    void init(int n) {
        this->n = n;
        tree.assign(4 * n, Node());
    }

    void pushDown(int node) {
        int left = 2 * node;
        int right = 2 * node + 1;

        // 1. Handle Frequency Updates
        // Optimization: Check if loop is needed
        bool hasLazy = false;
        for(int i=0; i<26; ++i) if(tree[node].lazy[i]) { hasLazy=true; break; }
        
        if (hasLazy) {
            for(int i = 0; i < 26; i++) {
                if(tree[node].lazy[i] != 0) {
                    int addVal = tree[node].lazy[i];
                    
                    tree[left].lazy[i] += addVal;
                    tree[left].arr[i] += addVal;
                    tree[left].maxFreq = max(tree[left].maxFreq, tree[left].arr[i]);

                    tree[right].lazy[i] += addVal;
                    tree[right].arr[i] += addVal;
                    tree[right].maxFreq = max(tree[right].maxFreq, tree[right].arr[i]);

                    tree[node].lazy[i] = 0;
                }
            }
        }

        // 2. Handle Distinct Count Updates
        if(tree[node].lazyDistinct != 0) {
            int val = tree[node].lazyDistinct;
            
            tree[left].lazyDistinct += val;
            tree[left].distinctCount += val;

            tree[right].lazyDistinct += val;
            tree[right].distinctCount += val;

            tree[node].lazyDistinct = 0;
        }
    }

    void updateFreq(int node, int start, int end, int l, int r, int charIdx, int val) {
        if (end < l || start > r) return;
        if (start >= l && end <= r) {
            tree[node].lazy[charIdx] += val;
            tree[node].arr[charIdx] += val;
            tree[node].maxFreq = max(tree[node].maxFreq, tree[node].arr[charIdx]);
            return;
        }
        pushDown(node);
        int mid = (start + end) / 2;
        updateFreq(2 * node, start, mid, l, r, charIdx, val);
        updateFreq(2 * node + 1, mid + 1, end, l, r, charIdx, val);
    }

    void updateDistinct(int node, int start, int end, int l, int r, int val) {
        if (end < l || start > r) return;
        if (start >= l && end <= r) {
            tree[node].lazyDistinct += val;
            tree[node].distinctCount += val;
            return;
        }
        pushDown(node);
        int mid = (start + end) / 2;
        updateDistinct(2 * node, start, mid, l, r, val);
        updateDistinct(2 * node + 1, mid + 1, end, l, r, val);
    }

    // Optimization: Return values by reference or use a global result holder 
    // to avoid copying the Node struct on return.
    // For simplicity, we just look at the specific values we need.
    void queryCheck(int node, int start, int end, int idx, int& mf, int& dc) {
        if (start == end) {
            mf = tree[node].maxFreq;
            dc = tree[node].distinctCount;
            return;
        }
        pushDown(node);
        int mid = (start + end) / 2;
        if (idx <= mid) queryCheck(2 * node, start, mid, idx, mf, dc);
        else queryCheck(2 * node + 1, mid + 1, end, idx, mf, dc);
    }

    int longestBalanced(string s) {
        int sz = s.size();
        init(sz);
        int maxL = 0;
        vector<int> lastOcc(26, -1);

        for (int r = 0; r < sz; r++) {
            int charIdx = s[r] - 'a';

            // Updates
            updateFreq(1, 0, sz - 1, 0, r, charIdx, 1);
            int prev = lastOcc[charIdx];
            updateDistinct(1, 0, sz - 1, prev + 1, r, 1);
            lastOcc[charIdx] = r;

            // Check
            for (int l = 0; l <= r; l++) {
                int len = r - l + 1;
                if (len <= maxL) break; // Pruning

                int mf, dc;
                queryCheck(1, 0, sz - 1, l, mf, dc);

                if (1LL * mf * dc == len) {
                    maxL = max(maxL, len);
                }
            }
        }
        return maxL;
    }
};