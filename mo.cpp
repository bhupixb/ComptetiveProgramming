// Seize the moment try to freeze it and own it, squeeze it and hold it,
// ‘Cause we consider these minutes golden.

#include <bits/stdc++.h>

using namespace std;

#define MP make_pair
#define F first
#define S second
#define pi pair<int,int> 

const unsigned mod = 1e9 + 7;
const unsigned N = 1e5 + 4;

int color[N], arr[N];
int id[N], ind, sz[N];
vector<int> g[N];
int ans[N];

void dfs(int to, int p) {
  sz[to] = 1;
  arr[++ind] = to;
  id[to] = ind;
  for (int from: g[to]) {
    if (from != p) {
      dfs(from, to);
      sz[to] += sz[from];
    }
  }
}

const int block = 431;

struct query {
  int l, r, idx, k;
  bool operator<(const query &y) const {
    int a = l / block, b = y.l / block;
    if (a == b) return r < y.r; // sort by r if both are in same block
    return a < b; // sort by block number if in different blocks
  }
};

int glAns[N], freq[N];

inline void del(int cl) {
  if (glAns[color[arr[cl]]] > 0) {
    freq[glAns[color[arr[cl]]]] -= 1;
  }
  glAns[color[arr[cl]]] -= 1; 
}
inline void add(int cl) {
  glAns[color[arr[cl]]] += 1;
  freq[glAns[color[arr[cl]]]] += 1;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  int n, q, u, v;
  cin >> n >> q;

  for (int i = 1; i <= n; ++i) {
    cin >> color[i];
  }

  for (int i = 1; i < n; ++i) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  dfs(1, 0);

  /*for (int i = 1; i <= ind; ++i) {
    cout << arr[i] << ' ' << id[i] << '\n';
  }*/

  vector<query> Q(q);

  for (int i = 0; i < q; ++i) {
    cin >> u >> v;
    Q[i].l = id[u];
    Q[i].r = id[u] + sz[u] - 1;
    Q[i].idx = i;
    Q[i].k = v;
  }
  
  sort(Q.begin(), Q.end());

  int cl = 0, cr = 0;
  // cl indicates -> excluded from [1, cl)
  // cr indicates -> included from [1, cr)

  for (const auto it: Q) {
    int l = it.l, r = it.r;

    // cout << "main : " << l << ' ' << r << '\n';
    // cout << "before : " << cl << ' ' << cr << '\n';

    while (cl < l) {
      del(cl);
      ++cl;
    }
    while (cl >  l) {
      add(cl - 1); // cl will be one index ahead of included index so cl - 1
      --cl;
    }
    while (cr <= r) {
      add(cr);
      ++cr; // at last when cr == r it points to r + 1
    }
    while (cr > r + 1) {
      del(cr - 1);
      --cr;
    }

    // cout << "after : " << cl << ' ' << cr << '\n';
    
    ans[it.idx] = freq[it.k];
  }
  
  for (int i = 0; i < q; ++i) {
    cout << ans[i] << '\n';
  }

  return 0;
}