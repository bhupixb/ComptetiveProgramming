
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool val(int r, int c) {
    return (r >= 0 && c >= 0 && r < n && c < m);
}

// returns the number of cells visited in the grid

int dfs(int r, int c) {
    if (!val(r, c)) return 0;
    if (vis[r][c] or a[r][c] != 0) return 0;
    // some other criteria maybe
    vis[r][c] = 1;
    int cnt = 1;
    for (int i = 0; i < 4; ++i) {
        int nr = dx[i] + r;
        int nc = dy[i] + c;
        if (val(nr, nc) && !vis[nr][nc]) {
            cnt += dfs(nr, nc);
        }
    }
    return cnt;
}
