#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 4;
int ans[N];

class fenwick{
  vector<int> bit;
  int N;
  public:   
  fenwick(int n) {
    N = n + 5;
    bit.resize(N);
  } 
  void add(int i, int val) {
    while (i < N) {
      bit[i] += val;
      i += (i & -i);
    }
  }
  int query(int i) {
    int ans(0);
    while (i > 0) {
      ans += bit[i];
      i -= (i & -i);
    }
    return ans;
  }
}; 

using pi = pair<int,int>;

signed main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n;
  cin >> n; 
  vector<pi> a(n);
  for (auto &it: a) {
    cin >> it.second >> it.first;
  }
  sort(a.begin(), a.end());
  fenwick ins(1e5 + 5);
  int q;
  cin >> q;
  vector<pair<pi,int>> query(q);
  for (int i = 0; i < q; ++i) {
    cin >> query[i].first.second;
    cin >> query[i].first.first;
    query[i].second = i;
  }
  sort(query.begin(), query.end());

  int i = 0, j = 0;

  for (int i = 0; i < q; ++i) {
    while (j < n && a[j].first <= query[i].first.first) {
      ins.add(a[j].second, 1);
      ++j;
    }
    int uptoRight = ins.query(query[i].first.first);
    int uptoLeftMinus1 = ins.query(query[i].first.second - 1);
    ans[query[i].second] = uptoRight - uptoLeftMinus1;
  }
  for (int i = 0; i < q; ++i) {
    cout << ans[i] << '\n';
  }
  return 0;
