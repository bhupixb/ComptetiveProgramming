const int N = 1e6 + 3;
 
#define int long long
#define MP make_pair
#define F first
#define S second
#define sz(s) ((int)s.size())
 
int rand(int l, int r){
  static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  uniform_int_distribution<int> ludo(l, r); return ludo(rng);
}

// srand(chrono::steady_clock::now().time_since_epoch().count());

char s[N];
 
struct Hash {
  vector<pair<int,int>> H, pre;
  static const int mod;
  Hash(const char *s, int N, int b1 = 41, int b2 = 53) :
    H(N + 5), pre(N + 5) {       
    pre[0].F = 1, b1 = rand(37, 1 << 10);
    pre[0].S = 1, b2 = rand(41, 1 << 9);
    int cur1 = 0, cur2 = 0;
    for (int i = 1; i <= N; ++i) {
      pre[i].F = mul(pre[i-1].F, b1);
      pre[i].S = mul(pre[i-1].S, b2);
      cur1 = add(mul(cur1, b1), (s[i] - 'a' + 1));
      cur2 = add(mul(cur2, b2), (s[i] - 'a' + 1));
      H[i].F = cur1, H[i].S = cur2;
    }   
  }
  pair<int,int> get_hash(int l, int r) {
    int rem1 = mul(pre[r-l+1].F, H[l-1].F);
    int rem2 = mul(pre[r-l+1].S, H[l-1].S);
    return MP(sub(H[r].F, rem1), sub(H[r].S, rem2));
  }
  int add(int x, int y){
    x += y; return (x >= mod ? x - mod : x);
  }
  int sub(int x, int y) {
    x -= y; return (x < 0 ? x + mod : x);    
  }
  int mul(int x, int y) {
    x *= y; 
    x = (x >> 31) + (x & mod);
    x = (x >> 31) + (x & mod);
    return x;
  }
};
const int Hash::mod = (1LL << 31) - 1;