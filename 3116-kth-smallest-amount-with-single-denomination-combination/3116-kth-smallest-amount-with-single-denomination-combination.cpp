class Solution {
public:
    #define ll long long
    int n;
    int mini;
    ll countMultiples(ll mid, vector<int>& coins) {
        ll totalCnt=0;
        for(int mask=1;mask<(1<<n);++mask) {
            ll currentLCM=1;
            for(int i=0;i<n;++i) {
                if(mask&(1<<i)) {
                    currentLCM=lcm(currentLCM,coins[i]);
                    if(currentLCM>mid) break;
                }
            }
            if(currentLCM>mid) continue;
            int numberOfElements=__builtin_popcount(mask);
            if(numberOfElements%2==1) {
                totalCnt+=(mid/currentLCM);
            } else {
                totalCnt-=(mid/currentLCM);
            }
        }
        return totalCnt;
    }
    long long findKthSmallest(vector<int>& coins, int k) {
        n=coins.size();
        mini=*min_element(coins.begin(),coins.end());
        ll low=mini;
        ll high=1ll*mini*k;
        ll ans=-1;
        while(low<=high) {
            ll mid=low+(high-low)/2;
            ll cnt=countMultiples(mid,coins);
            if(cnt>=k) {
                ans=mid;
                high=mid-1;
            } else {
                low=mid+1;
            }
        }
        return ans;
    }
};


// [3,6,9,12,15,...............]
// [6,12,18,24,................]
// [9,18,27,36,................]

// [3,6,9,12,15,18,]
// i think first we can find the gcd of some numbers like in test case 1
/*
    we have 3,6,9 and 3 is gcd of all 
    so we can ignore 6 and 9 and only focus on 3.....
    like 3,6,9.... will cover all the numbers

    so we can create one new array consisting only common gcds
    
    edge case if there is 1 present in the array then answer is k only

    else consider test case 2 we have [2,5]
    now we can take lcm of all of them to consider importantly
    2-> 2,4,6,8,10,12,14.................
    5->5,10,15,20,25,30,.................
    lcm(2,5)=10 -> 10,20,30,40,50........
    now the fight is for Kth number how to deal with it
    [2,5] and k=7

*/