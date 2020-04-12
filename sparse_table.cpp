#include <bits/stdc++.h>
using namespace std;

#define int long long
#define F first
#define S second
#define rep(i,a,n) for (int i = a; i <= n; ++i)
#define fo(i, n)   for (int i = 1; i <= n; ++i)
#define all(v)  v.begin(), v.end()
#define pb push_back
#define P pair < int, int > 
const int N = 3e3 + 5;
int gcd(int a, int b){
	while(a && b)
		a > b ? (a %= b) : (b %= a);
	return a + b;
}
int a[N];
class sparse{
    int tree[N][20], Log[N];
    public:    
    sparse() {
      Log[1] = 0;Log[2] = 1;
      int let = 1;
      for(int i = 3; i < N; ++i){
      	if(!(i & (i-1)))
          let += 1;
        Log[i] = let;
       }
    }
    void build(int n){     
       for(int i = 1; i <= n; ++i)
    		tree[i][0] = a[i];
       for(int j = 1; j <= 20; ++j) {
           for(int i = 1; i + (1 << j) <= n + 1; ++i)
             tree[i][j] = gcd(tree[i][j-1], tree[i + (1 << (j-1))][j-1]);
       }
    }
    int query(int l, int r){
       int j = Log[r-l+1];
         return gcd(tree[l][j], tree[r - (1 << j) + 1][j]);       
    }  
};
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    sparse obj;  
   




    return 0;
}