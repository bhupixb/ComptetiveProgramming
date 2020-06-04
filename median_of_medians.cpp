// Hint: Don't look, No need

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

vector<int> tmp, size_five;

int find_median(const vector<int> &ok, int l, int r) {
    size_five.clear();
    for (int i = l; i < r; ++i) size_five.push_back(ok[i]);
    sort(size_five.begin(), size_five.end());
    return size_five[(r - l) / 2];
}

int median_of_medians(vector<int> &v) {
    if (v.size() == 1) return v[0];
    int n = v.size(), upto = n / 5, i = 0;
    tmp.clear();
    while (i < upto) {
        int median = find_median(v, i, i + 5);
        tmp.push_back(median);
        i += 5;
    }
    if (i + 1 < n) tmp.push_back(find_median(v, i, n));
    return median_of_medians(tmp);
}
#define accuracy chrono::steady_clock::now().time_since_epoch().count()
int find_median_of_medians(const vector<int> &v) {
    auto it = v;
    return median_of_medians(it);
}

mt19937 rng(accuracy);

int rand(int l, int r){
  uniform_int_distribution<int> ludo(l, r);
  return ludo(rng);
}
vector<int> gen_array(int len, int minRange, int maxRange){
   assert(len >= 0 and len <= 5e6);
    vector<int> a(len);
    for (int &x: a) x = rand(minRange, maxRange);
    return a;
}
signed main() {
    fast;
    int n = rand(1e6, 5e6);
    auto ok = gen_array(n, 1, 1e9);
    cout << find_median_of_medians(ok) << '\n';

  return 0;
}
