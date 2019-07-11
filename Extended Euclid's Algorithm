#include "bits/stdc++.h"
using namespace std;

#define int long long

int extended_gcd(int a, int b, int &x, int &y) {
	if (!b) {
		// Base case a * 1 + b * 0 = gcd(a, 0)
		// which implies x = 1 and y = 0
		x = 1, y = 0;		
		return a;
	}
	int gcd = extended_gcd(b, a % b, x, y);
	// a * x + b * y = d (here d is gcd(a, b))
	// b * x + (a % b) * y = d (after the recursive call the equation becomes this)
	// b * x + (a - (a / b) * y) = d
	// a * y + b(x - (a / b) * y) = d (Rearranging)
	// which implies cofficient of a is y and cofficient of b is (x - (a/b)*y)
	
	int x1 = y, y1 = x - (a / b) * y;
	x = x1, y = y1;	
	return gcd;
}
 
inline void solve() {
	int x, y;
	int a = rand(), b = rand();
	// cout << a << ' ' << b << ' ';
	int gcd = extended_gcd(a, b, x, y);
	assert(gcd == a*x+b*y);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    srand(time(NULL));
    int t = 100000;
    // cin >> t; 
    while(t--)
                solve();
    return 0;
}
