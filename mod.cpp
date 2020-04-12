// Warning: Change mod and N according to the question

inline int add(int x, int y, int mod = ::mod) {
  x += y;
  if (x >= mod or x < 0) x %= mod;
  if (x >= 0) return x;
  return x + mod;
} 
inline int mul(int x, int y, int mod = ::mod) {
  if (x >= mod or x + mod < 0) x %= mod;
  if (y >= mod or y + mod < 0) y %= mod;
  x *= y;
  if (x >= mod or x + mod < 0) x %= mod;
  if (x >= 0) return x;
  return x + mod;
}
inline int sub(int x, int y, int mod = ::mod) {
  x -= y;
  if (x + mod < 0 or x >= mod) {
    x %= mod;
  }
  if (x >= 0) return x;
  return x + mod;
}
int po(int x, int n, int mod = ::mod) {
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

int fact[N], invFact[N];

void pre(){
  fact[0] = invFact[0] = invFact[1] = 1;

  for(int i = 1 ; i < N ; i++) {
   fact[i] = mul(fact[i-1], i);
  }

  for(int i = 2 ; i < N ; i++) {
   invFact[i] = mul((mod - mod / i), invFact[mod % i]);
  }

  for(int i = 1; i < N ; i++) {
   invFact[i] = mul(invFact[i-1], invFact[i]);
  }
}
int ncr(int n, int r){
  return mul(mul(fact[n], invFact[r]), invFact[n-r]);
} 