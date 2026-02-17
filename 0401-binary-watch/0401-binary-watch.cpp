class Solution {
public:
    vector<string> ans;
    vector<string> readBinaryWatch(int turnedOn) {
        for(int i=0;i<12;i++) {
            for(int j=0;j<60;j++) {
                bitset<6>b1(i);
                bitset<6>b2(j);
                if(b1.count() + b2.count() == turnedOn) {
                    if(i<10 && j<10) ans.push_back(to_string(i)+":"+"0"+to_string(j)); 
                    else if(i>=10 && j<10) ans.push_back(to_string(i)+":"+"0"+to_string(j));
                    else if(i<10 && j>=10) ans.push_back(to_string(i)+":"+to_string(j));
                    else ans.push_back(to_string(i)+":"+to_string(j));
                }
            }
        }
        return ans;
    }
};