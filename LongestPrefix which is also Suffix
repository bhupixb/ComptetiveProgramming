 
const int N = 5e5 + 5;
const int mod = (1LL<<31) - 1;
const int p = 123;
int pre[N], var[N];


inline int add(int x, int y) {
    return (x + y) % mod;
}
 
inline int mul(int x, int y) {
    return ((x % mod) * (y % mod)) % mod;
}

int po(int x, int n) {
    int res = 1;
    for (;n;) {
        if (n & 1) {
            res = mul(res, x);
        }
        x = mul(x, x);
        n /= 2;
    }
    return res;
}

// Longest Prefix which is also suffix of length atmost n - 1
int LPS(const string &s) {
    int n = s.size(), ans(0);
    if (n < 2) {
        return 0;
    }    
    var[0] = 1;
    for (int i = 1; i <= n; ++i) {
        var[i] = mul(var[i-1], p);     
        pre[i] = add(pre[i-1],mul(s[i-1], var[i]));                
    }
    rep(i,1,n-1) {
       int x = pre[i];
       int y = add(pre[n] - pre[n-i], mod);
       y = mul(y, po(var[n-i], mod - 2));       
       if (x == y) {
        ans = i;
       }
    }
    return ans;
}
