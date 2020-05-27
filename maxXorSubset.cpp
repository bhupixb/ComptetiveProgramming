// Don't Look

#pragma optimize("O2")
#include <bits/stdc++.h> 
#include "bits/stdc++.h" 

using namespace std;

#define int long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#ifndef bhupixb
  #define var(...) 
  #define stl(...) 
#endif

signed main() {
  fast;
  int n, x;
  cin >> n;
  vector<bitset<60>> a;
  vector<int> v(n);
  a.reserve(n);
  for (int i = 0; i < n; ++i) {
    cin >> x;
    a.emplace_back(bitset<60>(x));
    v[i] = x;
  }
  vector<bool> used(n);
  for (int b = 60; b >= 0; --b) {
    int ind = -1, mx = 0;
    for (int i = 0; i < n; ++i) {
      if (!used[i] && a[i][b]) {
        if (v[i] > mx) {
          mx = v[i];
          ind = i;
        }
      }
    }
    if (ind == -1) {
      continue;
    }
    used[ind] = true;    
    for (int i = 0; i < n; ++i) {
      if (ind == i or !a[i][b]) {
        continue;
      }
      a[i] ^= a[ind];
      v[i] ^= v[ind];
    }
    var(ind, b, v[ind]);
    stl(v);
  }
  stl(v);
  int answer = 0;
  for (int x: v) answer ^= x;
  cout << answer << '\n';

  return 0;
}
