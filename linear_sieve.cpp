vector<int> spf, primes;
void RunLinearSieve(int n) {
	spf.assign(n + 1, 0);
	for(int i = 2; i < n; ++i) {
		if(!spf[i]) {
			spf[i] = i;
			primes.push_back(i);
		}
		for(int x : primes) {
			int calc = i * x;
			if(x > spf[i] || calc > n) {
				break;				
			}
			spf[calc] = x;
		}
	}
}
