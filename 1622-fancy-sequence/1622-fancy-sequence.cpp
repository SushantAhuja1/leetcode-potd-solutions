#define ll long long
#define mod (int)(1e9+7)
class Fancy {
public:
    vector<ll> arr;
    Fancy() {
        
    }
    
    void append(int val) {
        arr.push_back(1ll*val);
    }
    
    void addAll(int inc) {
        int sz=arr.size();
        for(int i=0;i<sz;i++) {
            arr[i]=arr[i]+1ll*inc;
        }
    }
    
    void multAll(int m) {
        int sz=arr.size();
        for(int i=0;i<sz;i++) {
            arr[i]=1ll*((arr[i]%mod)*(m%mod))%mod;
        }
    }
    
    int getIndex(int idx) {
        int sz=arr.size();
        if(idx>=sz) return -1;
        return arr[idx]%mod;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */