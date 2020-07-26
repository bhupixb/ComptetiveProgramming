#include "bits/stdc++.h"
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

const int N = 1e5 + 6;

int up[N][18], in[N], out[N];
vector<int> g[N];
class LCA {
  int t = 0, n;
public:
  LCA() {
    memset(up, 0, sizeof up);
    for (int i = 0; i < N; ++i) {
      in[i] = out[i] = 0; g[i].clear();
    }
  }
  void dfs(int u, int p) {
    in[u] = ++t;
    up[u][0] = p;
    for (int i = 1; i < 18; ++i) {
      up[u][i] = up[up[u][i-1]][i-1];
      // f(u, i) = f(f(u, i-1), i-1); (Recurrence Relation)
    }
    for (auto i : g[u]) {
      if (i != p) {
        dfs(i, u);
      }
    }
    out[u] = ++t;
  }
  // Check if u is ancestor of v or not
  inline bool ancestor(int u, int v) {
    return (!u) or (in[u] <= in[v] && out[u] >= out[v]);
  }
  inline int lca(int u, int v) {
    if (ancestor(u, v)) {
      return u; // If u is ancestor of v
    } else if(ancestor(v, u)) {
      return v; // If v is ancestor of u
    } else {
      for (int i = 17; i >= 0; --i) {
        if (!ancestor(up[u][i], v)) {
          u = up[u][i];
        }
      }
    }
    return up[u][0];
  }
  void inp() {
    int l, r;
    cin >> n;
    for (int i = 1; i < n; ++i) {
      cin >> l >> r;
      g[l].push_back(r);
      g[r].push_back(l);
    }
    dfs(1, 1);
  }

};

signed main() {
  fast;
  LCA G;
  // G.inp();
  return 0;
}
