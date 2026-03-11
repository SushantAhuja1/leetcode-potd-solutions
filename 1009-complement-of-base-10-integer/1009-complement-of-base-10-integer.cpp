class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        string str="";
        while(n>0) {
            int d=n%2;
            str+=to_string(d);
            n/=2;
        }
        // reverse(str.begin(),str.end());
        // cout<<"str : "<<str<<endl;
        for(auto &i:str) {
            i=(((i-'0')^1)+'0');
        }
        // cout<<"str : "<<str<<endl;
        int l=str.length();
        int ans=0;
        int j=0;
        for(auto &i:str) {
            ans=ans+pow(2,j)*(i-'0');
            j++;
        }
        return ans;
    }
};