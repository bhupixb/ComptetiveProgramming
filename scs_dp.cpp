// I can't tell you what it really is,
// I can only tell you what it feels like.
#include "bits/stdc++.h"
using namespace std;
const int N = 1002;
class Sol{
  
  char a[N], b[N];
  int n, m, dp[N][N];
  char nextState[N][N];
  char ans[N][N];
public:
  int solve(int i, int j) {
    if (i == n+1 && j == m+1) return 0;
    if (i == n+1) return m-j+1;
    if (j == m+1) return n-i+1;
    if (dp[i][j] != -1) return dp[i][j];
    int ok = 1000, x, y, z;
    if (a[i] == b[j]) {
      ok = 1 + solve(i+1, j+1);
      nextState[i][j] = 'V';
      ans[i][j] = a[i];
    }
    else {    
      x = 1+solve(i+1,j);
      y = 1+solve(i,j+1);
      z = 2+solve(i+1,j+1);
      if (x < ok) {
        ok = x;
        ans[i][j] = a[i];
        nextState[i][j] = 'D';
      }
      if (y < ok) {
        ok = y;
        ans[i][j] = b[j];
        nextState[i][j] = 'R';
      }
      if (z < ok) {
        ok = z;
        ans[i][j] = '!';
        nextState[i][j] = 'V';
      }
      ok = min({x, y, z});
    }
    // cout << i << ' ' << j << ' ' << x << ' ' << y << ' ' << z << ' ' << ok << '\n';  
    return dp[i][j] = ok;
  }
  string go(string &s1, string &s2) {
     for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        dp[i][j] = -1;
        ans[i][j] = '@';
        nextState[i][j] = '@';
      }
     }
     n = s1.size(), m = s2.size();
     for (int i = 0; i < n; ++i) a[i+1] = s1[i];
      for (int i = 0; i < m; ++i) b[i+1] = s2[i];
    string fin;
    solve(1,1);  
    int i = 1, j = 1;
    while (i <= n && j <= m) {
      if (ans[i][j] != '!')
        fin += ans[i][j];
      else fin += a[i] + b[j];
      if (nextState[i][j] == 'V') ++i, ++j;
      else if (nextState[i][j] == 'D') ++i;
      else if (nextState[i][j] == 'R') ++j;  
    }
    while (i <= n) fin += a[i++];
    while (j <= m) fin += b[j++];
    return fin;
  }
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string a, b;
  cin >> a >> b;
  Sol instance;

  cout << "the super subsequence is : " << instance.go(a,b);
  return 0;
}
// 1). Try forming/rearranging the equations if any
// 2). If problem asks to count, try counting in reverse(it can be easier sometimes)
