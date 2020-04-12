#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int N = 100+7;
vector<int> v[N], euler;
int vis[N];
void dfs(int node){
    vis[node] = 1;   
    euler.push_back(node);
    for(auto i : v[node]){
        if(!vis[i]){
            dfs(i);
            euler.push_back(node);
        }
    }
}

int main(){
   ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int n, i, q, l, r;
    cin >> n >> q;
    for(i = 1; i <= q; i++){
        cin >> l >> r;
        v[l].push_back(r);
        v[r].push_back(l);
    }
    dfs(1);
    for(int x : euler)cout << x << ' ';

      return 0;
}
