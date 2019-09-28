// I can't tell you what it really is,
// I can only tell you what it feels like.
#include "bits/stdc++.h"
using namespace std;

typedef long long ll; 
int n = 3;

int solve(int i, int mask) {
    if (i == n) {        
        int temp = mask;              
        for (int j = 0; mask; ++j, mask /= 2) {            
            if (mask & 1) {                              
               // Do Something here
            }                        
        }        
        return __builtin_popcount(0);
    }
    return max(solve(i+1, mask|(1<<i)), solve(i+1, mask));
}

int main() { 
  // cin >> n;  
  cout << solve(0,0);
}
