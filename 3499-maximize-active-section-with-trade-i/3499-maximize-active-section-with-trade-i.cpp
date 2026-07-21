class Solution {
public:
    int getIndex(int i, vector<int>& arr) {
        int n = arr.size(), low = 0, high = n - 1, ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] > i) {
                high = mid - 1;
            } else {
                ans = mid;
                low = mid + 1;
            }
        }
        return ans;
    }

    int getRightIndexFor1(int i, vector<int>& oneIndexes) {
        int ub = upper_bound(oneIndexes.begin(), oneIndexes.end(), i) - oneIndexes.begin();
        if (ub >= oneIndexes.size()) {
            return oneIndexes.size() - 1; 
        }
        return ub;
    }

    int getLeftIndexFor1(int i, vector<int>& oneIndexes) {
        int idx = lower_bound(oneIndexes.begin(), oneIndexes.end(), i) - oneIndexes.begin();
        idx--;
        if (idx < 0) {
            return 0;
        }
        return idx;
    }

    int maxActiveSectionsAfterTrade(string s) {
        int n = s.length();
        vector<int> oneIndexes;
        
        // PADDING: We pad with -1 and n to avoid out-of-bounds math on the edges
        oneIndexes.push_back(-1);
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                oneIndexes.push_back(i);
            }
        }
        oneIndexes.push_back(n);
        
        // Total existing '1's (excluding our -1 and n padding)
        int totalOnes = oneIndexes.size() - 2; 
        int maxTradeGain = 0;
        
        // Find every block of '1's and use Binary Search to find adjacent '0' blocks
        for (int i = 0; i < n; ) {
            if (s[i] == '0') {
                i++;
            } else {
                int start = i;
                while (i < n && s[i] == '1') {
                    i++;
                }
                int end = i - 1; // The '1' block is strictly from `start` to `end`
                
                // BINARY SEARCH 1: Find the nearest '1' to the left of this block
                int leftOneIdx = getLeftIndexFor1(start, oneIndexes);
                int leftOnePos = oneIndexes[leftOneIdx];
                int leftZeroBlockLen = start - leftOnePos - 1;
                
                // BINARY SEARCH 2: Find the nearest '1' to the right of this block
                int rightOneIdx = getRightIndexFor1(end, oneIndexes);
                int rightOnePos = oneIndexes[rightOneIdx];
                int rightZeroBlockLen = rightOnePos - end - 1;
                
                // A valid trade merges a left 0-block and right 0-block around a 1-block.
                if (leftZeroBlockLen > 0 && rightZeroBlockLen > 0) {
                    maxTradeGain = max(maxTradeGain, leftZeroBlockLen + rightZeroBlockLen);
                }
            }
        }
        
        return totalOnes + maxTradeGain;
    }
};