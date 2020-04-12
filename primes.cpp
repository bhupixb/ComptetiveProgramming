#pragma GCC optimize("Ofast")
#pragma GCC target("avx")
#include <bits/stdc++.h>
const int NMAX = (int)1e8;
std::bitset<NMAX> bits;
int main() {
	bits.set();
	bits[0] = bits[1] = 0;
	for (int i = 2; i * i <= NMAX; i++) {
		if (bits[i]) {
			for (int j = i * i; j <= NMAX; j += i) bits[j] = 0;
		}
	}
	//iterate over primes
	int64_t sum(0);
	int cnt(0);
	for (int p = bits._Find_first(); p < bits.size(); p = bits._Find_next(p)) {
		sum += p;
		cnt++;
	}
    assert(bits.count() == cnt);
	std::cout << "sum = " << sum << std::endl;
	std::cout << "cnt = " << cnt << std::endl;
	return 0;
}
