class Solution {
public:
    string addBinary(string a, string b) {
        string ans="";
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int carry=0;
        int n=a.length(),m=b.length();
        //add padding
        if(n<m) {
            string padding(m-n,'0');
            a+=padding;
        } else if(n>m) {
            string padding(n-m,'0');
            b+=padding;
        }
        for(int i=0;i<a.length();i++) {
            int bitA=a[i]-'0';
            int bitB=b[i]-'0';
            int sum=bitA+bitB+carry;
            ans+=(sum%2)+'0';
            carry=sum/2;
        }
        if(carry) {
            ans+='1';
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};