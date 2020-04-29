vector<vector<int>> res;

template<typename T>
void manacher(const T &s) {
  int n = s.size();
  res.assign(2, vector<int>(n));
  // let l = res[1][i] - 1, here range(i - l, i + l) is a resindrome
  // let l = res[0][i], here range(i - l, i + l - 1) if valid then is resindrome 
  for (int i = 0, l = 0, r = -1; i < n; i++) {
    int k = (i > r) ? 1 : min(res[1][l + r - i], r - i + 1);
    while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
      k++;
    }
    res[1][i] = k--;
    if (i + k > r) {
      l = i - k;
      r = i + k;
    }
  }
  for (int i = 0, l = 0, r = -1; i < n; i++) {
    int k = (i > r) ? 0 : min(res[0][l + r - i + 1], r - i + 1);
    while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
      k++;
    }
    res[0][i] = k--;
    if (i + k > r) {
      l = i - k - 1;
      r = i + k ;
    }
  }  
}
using pi = pair<int,int>;

pi ask(int i, bool f = 0) {
  int l;
  if (f) {
    l = res[1][i] - 1;
    return make_pair(i - l, i + l);
  }
  l = res[0][i];
  return make_pair(i - l, i + l - 1);
