class Solution {
public:
    priority_queue<int>pq;
    int minStoneSum(vector<int>& piles, int k) {
        int sum=0;
        for(auto &i:piles) {
            pq.push(i);
            sum+=i;
        }
        for(int i=1;i<=k;i++) {
            int maxi=pq.top();
            pq.pop();
            int half=maxi/2;
            maxi-=half;
            sum-=half;
            pq.push(maxi);
        }
        return sum;
    }
};
//4,3,6,7
//3,2,3,3