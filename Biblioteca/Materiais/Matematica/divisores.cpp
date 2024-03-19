// Descricao: Calcula os divisores de c, sem incluir c, sem ser fatorado
// Complexidade: O(sqrt(c))
set<int> calculaDivisores(int c) {
	int lim = sqrt(c);
	set<int> divisors;
	
	for(int i = 1; i <= lim; i++) {
		if (c % i == 0) {
			if(c/i != i) 
				divisors.insert(c/i);
			divisors.insert(i);
		}
	}

	return divisors;
}