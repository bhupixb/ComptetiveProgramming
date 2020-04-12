#include <bits/stdc++.h>
using namespace std;

#define P pair < int, int > 
#define s second
#define f first
#define pb push_back
#define all(v)  v.begin(), v.end()
#define rep(i,a,n)  for(int i = a; i <= n; ++i)
#define lb(v, x)  lower_bound(all(v), x) - v.begin()
#define up(v, x)  upper_bound(all(v), x) - v.begin()
#define fo(i, n)   for (int i = 1; i <= n; ++i)

const int N = 1e4 + 5;
int a[N];
class merge_sort_tree{
		vector < int > tree[N << 2];
		public:
		void build(int l, int r, int node){
		    if(l == r){
		        tree[node].pb(a[l]);
		        return ;
		    }
		    int mid = l + r >> 1, lc = node + node, rc = 1 + lc;
		    build(l, mid, lc);    build(mid + 1, r, rc);

		    merge(all(tree[lc]), all(tree[rc]), back_inserter(tree[node]));
		}
		int query(int l, int r, int ql, int qr, int val, int node){
		    if(qr < l || r < ql)
		        return 0;
		    if(ql <= l and r <= qr){
		    		//returns number of elements strictly less than VAL(val)
		        int L = lower_bound(all(tree[node]), val) - tree[node].begin();
		        return  L;
		    }
		    int mid = l + r >> 1, lc = node + node, rc = 1 + lc;

		    return (query(l, mid, ql, qr, val, lc)
		    						 + query(mid + 1, r, ql, qr, val, rc));
		}
};
int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    merge_sort_tree obj;
   	int n, q, l, r, k;
   	cin >> n >> q;
   	fo(i, n)
   		cin >> a[i];
   
    obj.build(1, n, 1);
    return 0;
}