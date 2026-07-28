class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int>freq(26,0);
        bool isOddCharPresent=false;
        char oddChar;
        for(auto &i:s) {
            freq[i-'a']++;
        }
        for(int i=0;i<26;i++) {
            if(freq[i]%2) {
                isOddCharPresent=true;
                oddChar=i+'a';
            }
        }
        int oddCharFreq=0;
        if(isOddCharPresent)
            freq[oddChar-'a'];
        //if oddCharFreq==1 or oddCharFreq>1
        string half="";
        for(int i=0;i<26;i++) {
            if(freq[i]==0) continue;
            else if(freq[i]%2==0) {
                string x(freq[i]/2,i+'a');
                half+=x;
            } else if(freq[i]%2 && freq[i]>1) {
                string x(freq[i]/2,i+'a');
                half+=x;
            }  
        }
        string nextHalf=half;
        reverse(nextHalf.begin(),nextHalf.end());
        if(!isOddCharPresent)
            return half+nextHalf;
        return half+oddChar+nextHalf;
    }
};