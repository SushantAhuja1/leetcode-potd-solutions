class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int totalCost=0;
        int n=cost.size();
        sort(cost.rbegin(),cost.rend());
        for(int i=0;i<n;) {
            if(i+1<n) {
                totalCost+=(cost[i]+cost[i+1]);
                i+=3;
            } else {
                totalCost+=(cost[i]);
                break;
            }
        }
        return totalCost;
    }
};

// 6,5,7,9,2,2
// 9 7 6 5 2 2
// 