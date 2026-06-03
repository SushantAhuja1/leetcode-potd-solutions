class Solution {
public:
    vector<pair<int, int>> land, water;
    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
        return a.second > b.second;
    }
    bool isPossible(int mid) {
        // Since you sorted descending by end time, the minimum end time is at
        // the back.
        int minLandEnd = land.back().second;
        int minWaterEnd = water.back().second;

        // 1. Check if Land -> Water is possible within 'mid'
        bool landThenWater = false;
        for (const auto& w : water) {
            int duration = w.second - w.first;
            long long finishTime = max(minLandEnd, w.first) + duration;
            if (finishTime <= mid) {
                landThenWater = true;
                break;
            }
        }

        // 2. Check if Water -> Land is possible within 'mid'
        bool waterThenLand = false;
        for (const auto& l : land) {
            int duration = l.second - l.first;
            long long finishTime = max(minWaterEnd, l.first) + duration;
            if (finishTime <= mid) {
                waterThenLand = true;
                break;
            }
        }

        // If either valid sequence finishes within 'mid', it's possible
        return landThenWater || waterThenLand;
    }
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();
        int low = 1, high = 1e9, ans = high;
        land.resize(n);
        water.resize(m);
        for (int i = 0; i < n; i++) {
            land[i] = {landStartTime[i], landStartTime[i] + landDuration[i]};
        }
        for (int i = 0; i < m; i++) {
            water[i] = {waterStartTime[i],
                        waterStartTime[i] + waterDuration[i]};
        }
        sort(land.begin(), land.end(), cmp);
        sort(water.begin(), water.end(), cmp);
        // land->water = ans1
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        // water->land = ans2
        // return max(ans1,ans2)
        return ans;
    }
};

// {(2,6),(8,9)} -> land
// {(6,9)} -> water