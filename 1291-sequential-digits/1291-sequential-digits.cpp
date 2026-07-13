class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string lowStr=to_string(low);
        string highStr=to_string(high);
        int lowStrLen=lowStr.length();
        int highStrLen=highStr.length();
        vector<int>ans;
        // i need to generate sequential strings of length between [lowStrLen....highStrLen]
        for(int len=lowStrLen;len<=highStrLen;len++) {
            for(int digit=1;digit<=9-len+1;digit++) {
                vector<int>x(len);
                x.clear();
                for(int k=1;k<=len;k++) {
                    x.push_back(digit+k-1);
                }
                string str="";
                for(auto &i:x) {
                    str+=(i+'0');
                }
                int val=stoi(str);
                if(val>high) break;
                else if(val>=low && val<=high) {
                    ans.push_back(val);
                }
            }
        }
        return ans;
    }
};