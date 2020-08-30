
const int max_nodes = 5e5;
using edge = int32_t;
vector<edge> g[max_nodes];
bool vis[max_nodes];
struct graph {
    static void reset(int n) {
        for (int i = 0; i <= n; ++i) {
            g[i].clear();
            vis[i] = false;
        }
    }
    graph(int n) { reset(n); }
    void dfs(int u, int par = -1) {
        vis[u] = 1;
        for (auto v: g[u]) {
            if (!vis[v]) {
                dfs(v, u);
            }
        }
    }
    void add_edge(int u, int v) {
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
};
