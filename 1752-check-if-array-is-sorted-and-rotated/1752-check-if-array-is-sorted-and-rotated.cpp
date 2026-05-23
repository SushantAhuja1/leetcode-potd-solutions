class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        vector<int>sorted;
        for(auto &i:nums) {
            sorted.push_back(i);
        }
        sort(sorted.begin(),sorted.end());
        for(int k=1;k<=n+1;k++) {
            vector<int>arr(n);
            for(int i=0;i<n;i++) {
                arr[i]=sorted[(i+k)%n];
            }
            // for(auto &i:arr) {
            //     cout<<i<<" ";
            // }
            // cout<<endl;
            if(arr==nums) return 1;
        }
        return 0;
    }
};

// 1 2 3 4 
// 2 3 4 1
// 3 4 1 2
// 4 1 2 3
// 1 2 3 4
// 2 1 3 4 