// I can't tell you what it really is,
// I can only tell you what it feels like.
#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define E cout << '\n'
#define rep(i,a,n) for (int i = a; i <= n; ++i)
#define int long long

const int mod = 1e9 + 7;
const int N = 3e5 + 5;

vector < int > v[N], fin;
vector < int > revg[N];
bool vis[N];

void dfs(int node) {
	vis[node] = 1;
	// Dfs in graph G
	for (auto i : v[node]) {
		if (!vis[i]) {
			dfs(i);
		}
	}
	fin.pb(node);// According to finishing time
}

void dfs_rev(int node) {
	vis[node] = 1;
	cout << node << ' ';
	// Dfs in graph with inverted Edges
	for (auto i : revg[node]) {
		if (!vis[i]) {
			dfs_rev(i);
		}
	}
}
 
inline void solve() {
	int n, m, l, r, ways = 1;
	long long ans(0);
	cin >> n >> m;
	// n = number of nodes, m = number of edges (directed)	
	
	rep(i,1,m) {
		cin >> l >> r;
		v[l].pb(r); // Add direct edge
		revg[r].pb(l); // Add flipped edge
	}

	rep(i,1,n) {
		if (!vis[i]) {
			dfs(i);			
		}
	}
	
	// Reverse according to highest finishing time
	reverse(fin.begin(), fin.end());

	memset(vis, 0, sizeof(vis));

	for (auto i : fin) {		
		if (!vis[i]) {
			dfs_rev(i);
			cout << '\n';
			// Maintain a vector if component element required			
		}
	}
	
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
