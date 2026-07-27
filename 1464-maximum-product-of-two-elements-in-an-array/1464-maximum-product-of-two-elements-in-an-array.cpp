class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<>>pq;
        for(auto &i:nums) {
            if(pq.size()<2) {
                pq.push(i);
            } else if(pq.top()<i) {
                pq.pop();
                pq.push(i);
            }
        }
        int pr=1;
        while(!pq.empty()) {
            int ele=pq.top();
            // cout<<"ele : "<<ele<<endl;
            pr=pr*(ele-1);
            pq.pop();
        }
        return pr;
    }
};