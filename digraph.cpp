const int max_nodes = 5e5;
using edge = int32_t;
vector<edge> g[max_nodes];
int32_t vis[max_nodes];
struct digraph {
    int N;
    vector<int> topo;
    static void reset(int n) {
        for (int i = 0; i <= n; ++i) {
            g[i].clear();
            vis[i] = 0;
        }
    }
    digraph(int n) : N(n) { reset(n); }
    // return true if graph is DAG i.e. topo sort exists
    bool dfs(int u, int par = -1) {
        vis[u] = -1;
        bool exists = true;
        for (auto v: g[u]) {
            if (!vis[v]) {
                exists &= dfs(v, u);
            }
            else if (vis[v] == -1) {
                exists = false;
            }
        }
        vis[u] = 1;
        topo.push_back(u);
        return exists;
    }
    void add_edge(int u, int v) {
        g[u].emplace_back(v);
    }
    // return empty vector if no topological ordering exists
    vector<int> findTopoSort() {
        for (int i = 0; i <= N; ++i) vis[i] = 0;
        topo.reserve(N);
        bool pos = true;
        for (int i = 1; i <= N; ++i) {
            if (!vis[i]) {
                pos &= dfs(i);
            }
        }
        if (!pos) topo.clear();
        reverse(begin(topo), end(topo));
        stl(topo);
        return topo;
    }
};
