#include "bits/stdc++.h"
using namespace std;

// Uses 1.6e6 size array for finding primes upto 1e8
#define MAX 100000000
#define SQ 10000

#define check(n) (prime[n>>6]&(1<<((n&63)>>1)))
#define SET(n) prime[n>>6]|=(1<<((n&63)>>1))

int prime[MAX>>6];

vector < int >  GetPrimes() {
  vector < int > v;
  v.push_back(2);
  for (int i = 3; i < MAX; i += 2) {
    if (!check(i)) {
      v.push_back(i);
    }
  }
  return v;
}

int sieve(){
  for (int i = 3; i <= SQ; i += 2) {
    if (!check(i)) {
      int inc = i + i;
      for (int j = i * i; j < MAX; j += inc) {
        SET(j);
      }        
    }
  }
  return 0;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  sieve();
  vector < int > v(GetPrimes());
  for (int i = 0; i < 10; ++i) {
    cout << v[i] << ' ';
  }
  return 0;
}
