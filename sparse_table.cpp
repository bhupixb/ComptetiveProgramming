
const int mx = 20;
int a[N];
int tree[N][mx];
class sparse{
    public:
    void build(int n){
       for(int i = 1; i <= n; ++i) {
            tree[i][0] = a[i];
       }
       for(int j = 1; j <= mx; ++j) {
            for(int i = 1; i + (1 << j) <= n + 1; ++i) {
                tree[i][j] = gcd(tree[i][j-1], tree[i + (1 << (j-1))][j-1]);
            }
       }
    }
    int query(int l, int r){
        int j = log2(r - l + 1);
        return gcd(tree[l][j], tree[r - (1 << j) + 1][j]);
    }
};

