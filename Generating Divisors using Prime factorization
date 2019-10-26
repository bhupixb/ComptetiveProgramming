// I can't tell you what it really is,
// I can only tell you what it feels like.
#include "bits/stdc++.h"
using namespace std;
 
#define int long long
#define F first
#define S second
#define sz(x) ((int)x.size())
#define rep(i,a,n) for (int i = a; i <= n; ++i)
#define all(v)  v.begin(), v.end()
#define pb push_back
#define P pair < int, long long >
#define E cout << '\n'

const int mod = 1e9 + 7;
const int N = 1e5 + 5;

int a[N], k, currElement, ans = 0;
vector < P > v;
int h[N];

void generateDivisors(int idx, long long cur) {            
    if (idx >= sz(v))return;
    for (int i = 0; i <= v[idx].first; ++i) {
      // To prevent it from number of divisors extra calls
      if (idx + 1 < sz(v)) {
        generateDivisors(idx+1, cur);
        cur *= v[idx].S;
      }
      else {
        // let's consider this prime factorization
        // {{1,2}, {2,3}, {2,5}, {1,7}} in this example 7 will never be multiplied
        // in if condition as idx + 1 == sz(v) so we multiply it in else condition if i > 0
        if (i) {
          cur *= v[idx].S;
        }        
        // Here cur is the divisors formed
        cout << cur << ' ';
      }
    } 
}

vector < int > primes;
vector < int > spf;

void RunLinearSieve() {
  int n = N;
  spf.assign(n + 1, 0);
  spf[1] = 1;
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

void findPrimefactors(int n) {
  while (n != 1) {
    int ok = 1, pf = spf[n], cnt = 0;
    while (n > 1 && n % pf == 0) {
      ok *= pf;
      n /= pf;
      ++cnt;
    }   
    v.push_back({cnt, pf});
  }  
}

inline void solve() {
  int n;
  cin >> n;
  v.clear();    
  findPrimefactors(n);
  generateDivisors(0, 1);       
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);  
  RunLinearSieve();  
  solve();
  return 0;
}
