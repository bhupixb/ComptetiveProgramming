
struct DSU_on_Matrix {
	// Don't forget to initialize n and m
  int n, m;
  vector<int> par, sz;

  DSU_on_Matrix(int N = 2e5 + 3) :
   par(N), sz(N, 1) {
  	iota(par.begin(), par.end(), 0);
  	n = -1, m = -1;
  }

  int get(int r, int c) {
    return (r - 1) * m + c;
  }

  int find(int x) {
    if (x == par[x]) return x;
    return par[x] = find(par[par[x]]);
  }

  void join(int x, int y) {
  	assert(n != -1);
    int px = find(x), py = find(y);
    if (px == py) return;
    if (sz[px] > sz[py]) swap(px, py);
    par[px] = py;
    sz[py] += sz[px];
  }

};