// Unfortunately unordered_map solution takes less time than this
#include "bits/stdc++.h"
using namespace std;

#define F first
#define S second

// Struct for trie node (Memory Efficient)
struct node {
    unordered_map < char, node* > mp;
    int cnt = 0;
};

int ans = 0;

class trie {
    node *root;
public:
    trie () {
        root = NULL;
    }
    void insert(const string &s) {
        if (root == NULL) {
            root = new node;
        }
        node *temp = root;
        for (auto i : s) {
            if (temp->mp.find(i) == temp->mp.end()) {
                temp->mp[i] = new node;
            }
            temp = temp->mp[i];
        }
        temp->cnt += 1;
    }
    void dfs(node *temp) {
        if (temp == NULL) {
            return;
        }
        for (auto i : temp->mp) {
            if (i.S != NULL) {
                ans = max(i.S->cnt, ans);
                dfs(i.S);
            }
        }
    }
    void Do() {
        dfs(root);
    }
};

inline void solve() {
    int n;using namespace chrono;
    auto X = high_resolution_clock::now();
    string s;
    cin >> n;
    trie T;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        T.insert(s);
    }
    T.Do();

    auto Y = high_resolution_clock::now();
    // cout << setw(10) << "Estimated time = ";
    // cout << duration_cast<microseconds>(Y-X).count() / float(1e6) << "(uS)\n";

    cout << ans;
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
