
struct segtree { // with lazy propagation
  vector<int> tree, lazy;
  segtree() {
    tree.resize(N << 2);
    lazy.resize(N << 2);
  }  
  int combine(int a, int b) {
    return a + b;
  }
  void build(int l, int r, int x) {
    if(l == r) {
      // tree[x] = sum[l];
    }
    else {
      int mid = l + r >> 1, lc = x + x, rc = lc + 1;
      build(l, mid, lc);
      build(mid + 1, r, rc);
      tree[x] = combine(tree[lc], tree[rc]);
    }
  }
  void prop(int l, int r, int x) {
    if(lazy[x]) {
      tree[x] += lazy[x];
      if(l ^ r) {
        int lc = x + x, rc = lc + 1;
        lazy[lc] += lazy[x];
        lazy[rc] += lazy[x];
      }
      lazy[x] = 0;
    }
  }
  void update(int l, int r, int ql, int qr, int val, int x) {
    prop(l, r, x);
    if(qr < l || r < ql) {
      return;
    }
    if(ql <= l && r <= qr) {
      lazy[x] = val;
      prop(l, r, x);
      return;
    }
    int mid = l + r >> 1, lc = x + x, rc = lc + 1;

    update(l, mid, ql, qr, val, lc);  
    update(mid + 1, r, ql, qr, val, rc);

    tree[x] = combine(tree[lc], tree[rc]);
  }
  int query(int l, int r, int ql, int qr, int x) {
    prop(l, r, x);
    if(qr < l || r < ql) {
      return 0;
    }
    if(ql <= l and r <= qr) {
      prop(l, r, x);
      return tree[x];
    }
    int mid = l + r >> 1, lc = x + x, rc = lc + 1;

    return combine(query(l, mid, ql, qr, lc), query(mid + 1, r, ql, qr, rc));
  }
};