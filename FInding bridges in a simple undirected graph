#include "bits/stdc++.h"
using namespace std;

class find_bridges{
  public:
  vector<vector<int>> v;  
  vector<bool> vis;
  vector<int> low, tin;
  map<pair<int,int>,int> mp;  
  int timer, n, m;

  find_bridges(int x, int y) {
    n = x, m = y;
    v.resize(n);  
    timer = 1;
    vis.resize(n, 0);
    low.resize(n, -1);
    tin.resize(n, -1);
  }
  
  void dfs(int node, int p = -1) {
    vis[node] = 1;
    tin[node] = low[node] = timer++;
    for (int to : v[node]) {      
      if (to == p) continue;
      if (vis[to]) {
        low[node] = min(low[node], tin[to]);
      }
      else {
        dfs(to, node);
        low[node] = min(low[node], low[to]);

        // Here the bridge is found
        if (low[to] > tin[node]) {
          int x = node, y = to;   
          cout << x+1 << ' ' << y+1 << '\n';               
         }
      }
    }
  } 
  void find_bridgesFinal() {
    // Assume the graph to be connected    
    dfs(0); 
    for (int i = 0; i < n; ++i) {
      cout << i+1 << ' ' << low[i] << ' ' << tin[i] << '\n';
    }
  }
};
 
signed main() {
  int t, l, r;  
  t = 1;
  while (t--) {
    int n, m;
    cin >> n >> m;
    find_bridges solver(n, m);
    for (int i = 0; i < m; ++i) {
      cin >> l >> r;
      --l, --r;     
      solver.v[l].push_back(r);
      solver.v[r].push_back(l);
    }   
    solver.find_bridgesFinal();    
  }
  return 0;
}
