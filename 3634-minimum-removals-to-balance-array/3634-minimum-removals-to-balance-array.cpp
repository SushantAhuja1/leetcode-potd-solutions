class Solution {
public:
    int n;
    int maxi=0;
    int minRemoval(vector<int>& nums, int k) {
        n=nums.size();
        if(n==1) return 0;
        sort(nums.begin(),nums.end());
        int i=1,cnt=0;
        deque<int>q;
        q.push_front(nums[0]);
        cnt++;
        while(i<n) {
            int curr=nums[i];
            if(1ll*k*q.front()>=curr) {
                q.push_back(curr);
            } else {
                while(q.size()>0 && 1ll*curr>1ll*k*q.front()) {
                    q.pop_front();
                }
                q.push_back(curr);
            }
            maxi=max(maxi,(int)q.size());
            i++;
        }
        return n-maxi;
    }
};

//[1,2,5]
//[6,19,33] -> arr
//[6,19,33] i=0,j=2 -> arr
//[19,33] => 1+(19,33) or 1+(6,19) 
//[1,2,6,9] k=2 