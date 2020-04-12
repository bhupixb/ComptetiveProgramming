#include "bits/stdc++.h"
using namespace std;

#define int long long
#define P pair < int, int >
#define PP pair < int, P >
#define f first
#define s second
#define fast ios_base::sync_with_stdio(NULL);cin.tie(NULL);cout.tie(NULL);
const int N = 2e5 + 5;
vector < pair < int, int > > v[N];
int dist[N], vis[N];
int parent[N];
void Dijkstra(int node){
    fill(dist, dist + (int)1e5 + 1, 1e16);
    priority_queue < PP, vector < PP > , greater < PP > > q;
    dist[node] = 0;
    q.push({0, {node, node}});
    
    while(!q.empty()){
        auto temp = q.top();
        q.pop();
        if(vis[temp.s.f])
            continue;
        dist[temp.s.f] = temp.f;
        parent[temp.s.f] = temp.s.s;
        for(auto it : v[temp.s.f]){
            q.push({it.s + temp.f, {it.f, temp.s.f}});
        }
        vis[temp.s.f] = 1;
    }       
}
signed main(){
    fast;
    int n, m, l, r, wt;
    cin >> n >> m;
    stack < int > st;
    for(int i = 1; i <= m; ++i){
        cin >> l >> r >> wt;
        v[l].push_back({r, wt});
        v[r].push_back({l, wt});
    }
    Dijkstra(1);   
    if(dist[n] == 1e16)
        return cout << -1,0;
    int x = n;
    while(parent[x] != x)
            st.push(x), x = parent[x];
    cout << 1 << ' ';
    while(!st.empty())
        cout << st.top() << ' ', st.pop();
    return 0;
}