const int max_nodes = 5e5;
using edge = int32_t;
vector<edge> g[max_nodes];
int32_t subtreeSize[max_nodes];
struct tree {
    int N;
    static void reset(int n) {
        for (int i = 0; i <= n; ++i) {
            g[i].clear();
            subtreeSize[i] = 0;
        }
    }
    tree(int n) : N(n) { reset(n); }
    void dfs(int u, int par = -1) {
        subtreeSize[u] = 1;
        for (auto v: g[u]) {
            if (v != par) {
                dfs(v, u);
                subtreeSize[u] += subtreeSize[v];
            }
        }
    }
    void add_edge(int u, int v) {
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
};
