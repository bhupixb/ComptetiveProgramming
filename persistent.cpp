// I can't tell you what it really is,
// I can only tell you what it feels like.
#include "bits/stdc++.h"
using namespace std;
 
#define int long long
#define F first
#define S second
#define sz(x) ((int)x.size())
#define rep(i,a,n) for (int i = a; i <= n; ++i)
#define all(v)  v.begin(), v.end()
#define pb push_back
#define P pair < int, int >
#define E cout << '\n'

const int mod = 1e9 + 7;
const int N = 3e5 + 5;

int a[N], rst, pos[N];


struct node {
  node *l, *r;  int x;
  node() : x(0) {}
  node(int t) : l(nullptr), r(nullptr), x(t) {}
  node* combine(node* &a, node* &b) {
    this->l = a;  this->r = b;
    this->x = max(a->x, b->x);
    return this;
  }
  ~node() {if (l) delete l; if (r) delete r;}
};

node* build(int l, int r) {
  if (l == r) {
    return new node(a[l]);
  }
  int mid = l + r >> 1;
  node *L = build(l, mid);
  node *R = build(mid + 1, r);
  return (new node())->combine(L, R);
}
int query(int l, int r, int ql, int qr, node *cur) {
  if (r < ql || qr < l) return -1e9;
  if (ql <= l && r <= qr) {
    return cur->x;
  }
  int tm = l + r >> 1;
  int L = query(l, tm, ql, qr, cur->l);
  int R = query(tm+1, r, ql, qr, cur->r);
  return max(L, R);
}
void update(int l, int r, int pos, int val, node *cv, node *pv) {
	if (pos < l || pos > r) return ;	
	if (l == r && l == pos) {
		cv->x = val; return;
	}
	int mid = l + r >> 1;
	if (pos <= mid) {
		cv->r = pv->r;
		cv->l = new node;
		update(l, mid, pos, val, cv->l, pv->l);
		cv->combine(cv->l, cv->r);
	}
	else {
		cv->l = pv->l;
		cv->r = new node;
		update(mid + 1, r, pos, val, cv->r, pv->r);
		cv->combine(cv->l, cv->r);
	}
} 
inline void solve() {
  int n;
  cin >> n;
  rep(i,1,n)cin>> a[i];
  node* ar[10];
  ar[1] = build(1, n);
  cout << query(1, n, 3, 3, ar[1])<< ' ';
  ar[2] = new node;
  update(1, n, 4, -1, ar[2], ar[1]);
  cout << query(1, n, 4, 4, ar[2]);
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  //cin >> t; while(t--)
  solve();
  return 0;
}