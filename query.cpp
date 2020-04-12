#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;


vector<pair<ll, ll> > order;
bool visit[N];
ll ht[N], st[N], sz[N], bit[N], mx = N, ans[N];
vector<ll> v[N];

void upd(ll idx, ll val){
	while(idx < mx){
		bit[idx] += val;
		idx += (idx & -idx);
	}
}

ll get(ll idx){
	ll sum = 0;
	while(idx > 0){
		sum += bit[idx];
		idx -= (idx & -idx);
	}
	return sum;
}

struct Q{
	int l, r, x, nd;
} querry[N];

bool cmp(Q q1, Q q2){
	return q1.x < q2. x;
}

void dfs(ll node, ll lv){
	visit[node] = 1;
	ht[node] = lv;
	st[node] = (int)order.size();
	order.push_back({ht[node], st[node]});
	for(auto i: v[node]){
		if(!visit[i]){
			dfs(i, lv + 1);
			sz[node] += sz[i];
		}
		
	}
	sz[node] += 1;
}


int main(){
	fast;
	ll n, k;
	cin >> n >> k;
	for(int i = 0; i < n - 1; i++){
		ll x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1, 1);
	sort(order.begin(), order.end());
	for(int i = 1; i <= n; i++){
		querry[i - 1].nd = i;
		querry[i - 1].x = ht[i] + k;
		querry[i - 1].l = st[i];
		querry[i - 1].r = st[i] + sz[i] - 1;
 	}
	sort(querry, querry + n, cmp);
	ll cur = 0;
	for(int i = 0; i < n; i++){
		while(cur < n && order[cur].first <= querry[i].x){
			upd(order[cur].second + 1, 1);
			cur++;
		}
		ans[querry[i].nd] = get(querry[i].r + 1) - get(querry[i].l);
	}
	for(int i = 1; i <= n; i++) cout << ans[i] << "\n";
	
	return 0;
}

