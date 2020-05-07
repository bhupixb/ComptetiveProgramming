#include <bits/stdc++.h>

using namespace std;

#define int long long

using pi = pair<pair<int,int>,int>;
#define MP make_pair

pi slopeFind(int x1, int y1, int x2, int y2) {
  int cx = y1 - y2;
  int cy = x2 - x1;
  int c = x1*y2 - y1*x2;
  int g = (gcd(cx, gcd(cy, c)));
  cx /= g, cy /= g, c /= g;
  if (cx < 0 || (cx == 0 && cy < 0)) {
    cx *= -1, cy *= -1, c *= -1;
  }
  return MP(MP(cx, cy), c); 
}

signed main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  

  return 0;
