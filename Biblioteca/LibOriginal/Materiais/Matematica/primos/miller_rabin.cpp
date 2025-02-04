// Teste de primalidade de Miller-Rabin
// Complexidade: O(k*log^3(n)), onde k eh o numero de testes e n eh o numero a ser testado
// Descicao: Testa se um numero eh primo com uma probabilidade de erro de 1/4^k

int mul(int a, int b, int m) {
	int ret = a*b - int((long double)1/m*a*b+0.5)*m;
	return ret < 0 ? ret+m : ret;
}

int pow(int x, int y, int m) {
	if (!y) return 1;
	int ans = pow(mul(x, x, m), y/2, m);
	return y%2 ? mul(x, ans, m) : ans;
}

bool prime(int n) {
	if (n < 2) return 0;
	if (n <= 3) return 1;
	if (n % 2 == 0) return 0;
	int r = __builtin_ctzint(n - 1), d = n >> r;

 	// com esses primos, o teste funciona garantido para n <= 2^64
	// funciona para n <= 3*10^24 com os primos ate 41
	for (int a : {2, 325, 9375, 28178, 450775, 9780504, 795265022}) {
		int x = pow(a, d, n);
		if (x == 1 or x == n - 1 or a % n == 0) continue;
		
		for (int j = 0; j < r - 1; j++) {
			x = mul(x, x, n);
			if (x == n - 1) break;
		}
		if (x != n - 1) return 0;
	}
	return 1;
}