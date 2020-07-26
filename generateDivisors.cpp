// I can't tell you what it really is,
// I can only tell you what it feels like.
#include "bits/stdc++.h"
using namespace std;
#define int long long
const int N = 4e5 + 2;

vector<int32_t> spf, primes;
void RunSieve(const int N) {
  spf.resize(N+1);
  iota(spf.begin(), spf.end(), 0);
  for (int i = 2; i < N; i += 2) {
    spf[i] = 2;
  }   
  for(int i = 3; i * i < N; i += 2) {
    if (spf[i] == i) {
      for (int j = i * i; j < N; j += i<<1) {
        if (spf[j] == j) {
          spf[j] = i;
        }
      }
    }
  }
}

template<typename T, typename T2>
void generateDivisors(int id, int cur, T &pf, T2 &div) {
  if (id == (size_t)pf.size()) {
    div.push_back(cur);
  }
  else {
    for (int i = 0; i <= pf[id].second; ++i) {
      generateDivisors(id+1, cur, pf, div);
      cur *= pf[id].first;
    }
  }
}

vector<int> primeFactorization(int n) {  
  vector<pair<int,int>> pf;
  vector<int> div;
  if (n < 2) div = {1};
  else {
    int cur = n;
    do {
      int cpf = spf[cur], exp = 0;
      while (cur % cpf == 0) {
        cur /= cpf, ++exp;
      }
      pf.push_back(make_pair(cpf,exp));
    } while (cur > 1);    
    generateDivisors(0,1,pf, div);
  }  
  return div;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);



  
  return 0;
}
// 1). Try forming/rearranging the equations if any
// 2). If problem asks to count, try counting in reverse(it can be easier sometimes)
