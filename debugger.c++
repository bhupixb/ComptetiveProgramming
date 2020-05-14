#include "bits/stdc++.h"
using namespace std;
 
#define int long long

template <typename A, typename B>
string to_string(pair<A, B> p);

string to_string(const string&);

string to_string(const char* s);

string to_string(bool b);

template <typename A>
string to_string(A v);

template <typename A, typename B>
string to_string(pair<A, B> p);

void debug_out(); 

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T);

vector<string> vec_splitter(string s);
void debug_var(
vector<string> __attribute__ ((unused)) args,
__attribute__ ((unused)) int idx, 
__attribute__ ((unused)) int LINE_NUM) { cerr << endl; } 

template <typename Head, typename... Tail>
void debug_var(vector<string>, int, int, Head, Tail...);

#define bhupixb 
#define var(...) debug_var(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#define stl(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

string to_string(const string& s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "T" : "F");
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

template <typename Head, typename... Tail>
void debug_var(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
  if(idx > 0) cerr << ", "; else cerr << "Line(" << LINE_NUM << "): ";
  stringstream ss; ss << H;
  cerr << args[idx] << " = " << ss.str();
  debug_var(args, idx + 1, LINE_NUM, T...);
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

vector<string> vec_splitter(string s) {
  s += ',';
  vector<string> res;
  while(!s.empty()) {
    res.push_back(s.substr(0, s.find(',')));
    s = s.substr(s.find(',') + 1);
  }
  return res;
}
