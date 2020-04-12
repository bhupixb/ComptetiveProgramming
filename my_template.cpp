#include "bits/stdc++.h"
using namespace std;
 
#define int long long
#define F first
#define S second
#define sz(x) ((int)x.size())
#define rep(i,a,n) for (int i = a; i <= n; ++i)
#define repd(i,a,n) for (int i = a; i >= n; --i)
#define all(v)  v.begin(), v.end()
#define pb push_back
#define pi pair <int, int>
#define E cout << '\n'
typedef unsigned ui;

// Can't be used to print c style arrays as begin isn't defined.
void out(int x) {cout << x;}
void out(int32_t x) {cout << x;}
void out(char x) {cout << '\'' << x << '\'';}
void out(const char *x) {cerr << '\"' << x << '\"';}
void out(const string &x) {cout << '\"' << x << '\"';}
void out(bool x) {cout << (x ? "true" : "false");}
template<typename T, typename V>
void out(const pair<T, V> &x) {cout << '{'; out(x.first); cout << ','; out(x.second); cout << '}';}
template<typename T>
void out(const T &x) {int f = 0; cout << '{'; for (auto &i: x) cout << (f++ ? "," : ""), out(i); cout << "}";}
void _print() {cout << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {out(t); if (sizeof...(v)) cout << ", "; _print(v...);}
#define deb(x...) cout << "[" << #x << "] = ["; _print(x)

const ui mod = 1e9 + 7;
const ui N = 1e6 + 5; 

int add(int,int,int t = mod); int mul(int,int,int t = mod);int sub(int,int,int t = mod);int po(int,int,int t = mod);
void preCompute(const int x = ::N);int ncr(int, int);int inv(int); void LinearSieve(int t = N);int rand(int,int);
bool isPrime(int); bool naivePrime(int);

vector<int> fact, invFact;
vector<int> spf, primes;

ui solve() {
  










  return 0; 
}

signed main() {
  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
  srand(chrono::steady_clock::now().time_since_epoch().count());  
  // preCompute();
  // LinearSieve();
  // int t = 1; cin >> t; rep(i,1,t)
  {
    // cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}

inline int add(int x, int y, int mod) {
  x += y;
  if (x >= mod or x < 0) x %= mod;
  if (x >= 0) return x;
  return x + mod;
} 
inline int mul(int x, int y, int mod) {
  if (x >= mod or x + mod < 0) x %= mod;
  if (y >= mod or y + mod < 0) y %= mod;
  x *= y;
  if (x >= mod or x + mod < 0) x %= mod;
  if (x >= 0) return x;
  return x + mod;
}
inline int sub(int x, int y, int mod) {
  x -= y;
  if (x + mod < 0 or x >= mod) {
    x %= mod;
  }
  if (x >= 0) return x;
  return x + mod;
}
int po(int x, int n, int mod) {
  int res = 1;
  for (;n > 0;) {
    if (n & 1) {
      res = mul(res, x, mod);
    }
    x = mul(x, x, mod);
    n /= 2;
  }
  return res;
}
int rand(int l, int r){
  static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  uniform_int_distribution<int> ludo(l, r); return ludo(rng);
}
void preCompute(const int N){
  fact.resize(N);
  invFact.resize(N);
  fact[0] = invFact[0] = invFact[1] = 1;
  for(int i = 1 ; i < N ; i++) {
   fact[i] = mul(fact[i-1], i);
  }
  for(int i = 2 ; i < N ; i++) {
   invFact[i] = mul((mod - mod / i), invFact[mod % i]);
  }
  // comment the below line if inverse of factorial not required
  for(int i = 1; i < N ; i++) {
   invFact[i] = mul(invFact[i-1], invFact[i]);
  }
}

bool isPrime(const int x) { 
  assert(x < (ui)spf.size());
  return (x > 1 && spf[x] == x);
}

bool naivePrime(int n) {
  if (n == 1 || (!(n & 1) && n > 2)) return 0;
  int i = 3, sqrtn = sqrt(n);
  while (i <= sqrtn) {
    if (n % i == 0) return 0;
    i += 2;
  }
  return 1;
}

auto factorize(int n) {  
  assert(spf[0] > 0);
  vector<pair<int,int>> pf;  
  do {
    int cpf = spf[n], exp = 0;
    while (n % cpf == 0) {
      n /= cpf, ++exp;
    }
    pf.push_back(make_pair(cpf,exp));
  } while (n > 1);        
  return pf;
}

int ncr(int n, int r){  
  assert(n < (ui)fact.size());
  return mul(mul(fact[n], invFact[r]), invFact[n-r]);
}

int inv(int n) {
  return po(n, mod - 2);
}

void LinearSieve(int n) { 
  spf.assign(n + 1, 0);
  for(int i = 2; i < n; ++i) {
    if(!spf[i]) {
      spf[i] = i;
      primes.push_back(i);
    }
    for(int x : primes) {
      int calc = i * x;
      if(x > spf[i] || calc > n) {
        break;        
      }
      spf[calc] = x;
    }
  }
}
