// Descricao: Calcula o n-esimo numero de Fibonacci modulo P
// Complexidade: O(log(n))

int mostSignificantBitPosition(int n) {
	int msb_position = 63;
	while (!((1 << (msb_position-1) & n)) && msb_position >= 0)
		msb_position--;
	return msb_position;
}

int fib (int n, int P) {

	int msb_position = mostSignificantBitPosition(n);

	int a=0, b=1; 

	for (int i=msb_position; i>=0;--i) {       
		int d = (a%P) * ((b%P)*2 - (a%P) + P),
			e = (a%P) * (a%P) + (b%P)*(b%P);
		a = d % P;
		b = e % P;

		if (((n >> i) & 1) != 0) {
			int c = (a + b) % P;
			a = b;
			b = c;
		}
	}
	return a;
}  