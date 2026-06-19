class Solution {
public:
    int largestAltitude(vector<int>& gain) {
       int n = gain.size();
       int maxi=0;
       int diff=0;
       for(int i=0;i<n;i++){
        maxi=max(maxi,diff+gain[i]);
        diff+=gain[i];
       } 
       return maxi;
    }
};