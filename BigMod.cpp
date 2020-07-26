#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef unsigned long long int LL;
const LL mod = 1e10;
LL bigMod(LL  a, LL  b, LL c) {
    if (a == 0 || b == 0) {
        return 0;
    }
    if (a == 1) {
        return b;
    }
    if (b == 1) {
        return a;
    }

    // Returns: (a * b/2) mod c
   LL a2 = bigMod(a, b / 2, c);

    // Even factor
    if ((b & 1) == 0) {
        // [((a * b/2) mod c) + ((a * b/2) mod c)] mod c
        return (a2 + a2) % c;
    } else {
        // Odd exponent
        // [(a mod c) + ((a * b/2) mod c) + ((a * b/2) mod c)] mod c
        return ((a % c) + (a2 + a2)) % c;
    }
}
LL po(LL x, LL n){
    LL res = 1LL;
    while(n){
        if(n & 1){
            if(res > 1e9 || x > 1e9)
            res = bigMod(res, x, mod) % mod;
            else
                res = (res * x) % mod;
        }
        n = n / 2;
       if(x > 1e9)
        x = bigMod(x, x, mod);
        else{
            x = (x * x) % mod;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a = n, b = n, c = n + 1;
        int get = bigMod
    }
    return 0;
}
