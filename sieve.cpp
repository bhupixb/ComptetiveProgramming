vector<bool> h(N);
vector<int> primes;

void RunSieve(int n) {
	for(int i = 4; i < N; i += 2) {
		h[i] = true;
	}
	int sq = sqrt(N), x;
	for(int i = 3; i < sq; i += 2) {
		if(h[i])
			continue;
		x = i + i;
		for(int j = i * i; j < N; j += x)
			h[j] = true;
	}
	for(int i = 2; i < N; ++i) {
		if(!h[i])
			primes.push_back(i);
	}
}
