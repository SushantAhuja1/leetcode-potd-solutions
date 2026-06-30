class Solution {
public:
    int numberOfSubstrings(string s) {
        int l=0,r=0,n=s.length(),a=0,b=0,c=0;
        int ans =0;
        while(r<n){
            if(s[r]=='a')a++;
            else if(s[r]=='b')b++;
            else c++;

            while(a>=1 && b>=1 && c>=1 ){
                ans+=n-r;
                if(s[l]=='a')a--;
                else if(s[l]=='b')b--;
                else c--;

                l++;
            }
            r++;
        }
        return ans;

    }
};