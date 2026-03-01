class Solution {
public:
    int minPartitions(string n) {
        char maxi='0';
        for(auto &i:n) {
            maxi=max(maxi,i);
        }      
        return maxi-'0';
    }
};