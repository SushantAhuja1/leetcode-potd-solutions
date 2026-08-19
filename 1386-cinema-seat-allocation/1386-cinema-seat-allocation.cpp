class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,set<int>>mp;
        for(auto &seat:reservedSeats) {
            int row=seat[0],col=seat[1];
            mp[row].insert(col);
        }
        int sz=mp.size();
        int ans=2*(n-sz);
        // cout<<"ans : "<<ans<<endl;
        for(auto &i:mp) {
            // cout<<"i : "<<i.first<<endl;
            set<int>st=i.second;
            if((!st.count(2) && !st.count(3) && !st.count(4) && !st.count(5)) && (!st.count(6) && !st.count(7) && !st.count(8) && !st.count(9))) {
                ans+=2;
                // cout<<"first"<<endl;
            } else if((!st.count(2) && !st.count(3) && !st.count(4) && !st.count(5))) {
                ans+=1;
                // cout<<"second"<<endl;
            } else if((!st.count(6) && !st.count(7) && !st.count(8) && !st.count(9))) {
                ans+=1;
                // cout<<"third"<<endl;
            } else if((!st.count(4) && !st.count(5) && !st.count(6) && !st.count(7))) {
                ans+=1;
                // cout<<"four"<<endl;
            }
        }
        return ans;
    }
};