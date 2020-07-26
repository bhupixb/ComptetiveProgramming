#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 3;

// Suffix array construction in O(NlogN)

vector<int> suffix_array(string const &s) {
    int n = s.size(), N = n + 256;
    vector<int> sa(n), ra(n);
    for(int i = 0; i < n; i++) sa[i] = i, ra[i] = s[i];
    for(int k = 0; k < n; k ? k <<= 1 : k++) {
        vector<int> nsa(sa), nra(n), cnt(N);
        for(int i = 0; i < n; i++) nsa[i] = (nsa[i] - k + n) % n;
        for(int i = 0; i < n; i++) cnt[ra[i]]++;
        for(int i = 1; i < N; i++) cnt[i] += cnt[i - 1];
        for(int i = n - 1; i >= 0; i--) sa[--cnt[ra[nsa[i]]]] = nsa[i];

        int r = 0;
        for(int i = 1; i < n; i++) {
            if(ra[sa[i]] != ra[sa[i - 1]]) r++;
            else if(ra[(sa[i] + k) % n] != ra[(sa[i - 1] + k) % n]) r++;
            nra[sa[i]] = r;
        }
        ra = nra;
    }
    return sa;
}

// longest common prefix using kasai O(N)

vector<int> kasai(string const &s, vector<int> const &sa) {
    int n = s.size(), k = 0;
    vector<int> ra(n), lcp(n);
    for(int i = 0; i < n; i++) ra[sa[i]] = i;
    auto F = [n] (int x) { return x >= n ? x - n : x; };
    for(int i = 0; i < n; i++) {
        if(k) k--;
        if(ra[i] == n - 1) {k = 0; continue;}
        int j = sa[ra[i] + 1];
        while(k < n && s[F(i + k)] == s[F(j + k)]) k++;
        lcp[ra[i]] = k;
        if(ra[F(sa[ra[i]] + 1)] > ra[F(sa[ra[j]] + 1)]) k = 0;
    }
    return lcp;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string a("abbaba");
    a += '$';
    auto suffix_array_perm = suffix_array(a);
    for (int x: suffix_array_perm) {
        cout << x << ' ' << a.substr(x) << '\n';
    }
    cout << '\n';
    auto it2 = kasai(a, suffix_array_perm);
    for (int i = 1; i < it2.size(); ++i) {
        cout << it2[i - 1] << ' ';
    }
    return 0;
}

