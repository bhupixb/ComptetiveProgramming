// I can't tell you what it really is,
// I can only tell you what it feels like.
#include "bits/stdc++.h"
using namespace std;
 
// #define int long long
struct node {
	node *a[2];
	int cnt[2];
	node() {
		for (int i = 0; i < 2; ++i) {
			a[i] = NULL;
			cnt[i] = 0;
		}
	}	
};
const int N = 3e5+ 4;
#define rep(i,a,n) for (int i = a; i <= n; ++i)
int a[N];

node *head;
int ans = 0;

void insert(int n) {
	node *temp = head;
	for (int i = 30; i >= 0; --i) {
		bool now = (n & (1LL<<i));
		if (temp->a[now] == NULL) {
			temp->a[now] = new node;
		}
		++temp->cnt[now];
		// If current bit of n is set then add numbers with this bit zero to the answer
		if (now && temp->a[now^1] != NULL) {
			ans += temp->cnt[now^1];
		}
		temp = temp->a[now];
	}
}

inline void solve() {
   int n;
   head = new node;
   cin >> n;
   rep(i,1,n) {
   	cin >> a[i];
   }
   for (int i = n; i; --i) {
   	insert(a[i]);
   }
   cout << ans << '\n';
   ans = 0;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  // cin >> t; while(t--)
  solve();
  return 0;
}
