class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int cnt=0,n=costs.size(),sum=0;
        for(int i=0;i<n;i++) {
            if(sum+costs[i]<=coins) {
                cnt++;
                sum+=costs[i];
            }
            else 
                break;
        }
        return cnt;
    }
};