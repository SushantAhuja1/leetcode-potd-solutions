class Solution {
public: 
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        long long curr=mass;
        for(auto &i:asteroids) {
            if(curr>=i) {
                curr+=i;
            } else {
                return false;
            }
        }
        return true;
    }
};