class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        vector<int>arr(3,0);
        for(auto &i:stones) {
            arr[i%3]++;
        }
        if(arr[1]==0 && arr[2]==0) {
            return false;
        }
        if(arr[0]%2==0) {
            return arr[1]>0 && arr[2]>0;
        }
        return abs(arr[1]-arr[2])>2;
        //1-1-2-1-2-1......
        //2-2-1-2-1-2......

    }
};


// loose if sum of removed stones value is divisible by 3 