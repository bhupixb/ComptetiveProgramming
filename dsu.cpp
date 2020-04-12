
struct DSU {  
  vector<int> par, sz;
  
  DSU(int N = 2e5 + 3) :
    par(N), sz(N, 1) {
    iota(par.begin(), par.end(), 0);
    cout << sz[1];
  }
  int find(int x) {
    if (x == par[x]) return x;
    return par[x] = find(par[par[x]]);
  }
  void join(int x, int y) {
    int px = find(x), py = find(y);
    if (px == py) return;
    if (sz[px] > sz[py]) swap(px, py);
    par[px] = py;
    sz[py] += sz[px];
  }

};
