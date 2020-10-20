int ternary_search(int lo, int hi) {
    while(lo < hi - 2) {
        int m1 = (lo * 2 + hi) / 3;
        int m2 = (lo + hi * 2) / 3;
        if(calc(m1) <= calc(m2)) {
            hi = m2;
        }
        else {
            lo = m1;
        }
    }
    int ans = calc(lo);
    for(int i = lo + 1; i <= hi; i++) {
        ans = min(ans, calc(i));
    }
    return ans;
}
