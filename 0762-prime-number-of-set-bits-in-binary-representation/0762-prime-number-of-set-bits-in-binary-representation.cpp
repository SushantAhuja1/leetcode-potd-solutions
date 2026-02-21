class Solution {
public:
    bool isPrime(int i) {
        if(i<=1) return false;
        if(i<=3) return true;
        if(i%2==0 || i%3==0) return false;
        for(int t=4;t<=sqrt(i);t++) {
            if(i%t==0) return false;
        }
        return true;
    }
    int countPrimeSetBits(int left, int right) {
        int cnt=0;
        for(int i=left;i<=right;i++) {
            bitset<32>b(i);
            int setBits=b.count();
            if(isPrime(setBits)) cnt++;
        }
        return cnt;
    }
};