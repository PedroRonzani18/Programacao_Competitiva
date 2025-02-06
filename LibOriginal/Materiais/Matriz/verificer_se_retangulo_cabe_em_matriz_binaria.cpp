// Description: Verifica se um retangulo C X L cabe em uma matriz binaria N X M
// Compçlexidade: O(N*M)
// OBS: comprimParaAltura[i] = maior comprimento de retângulo de 1's com altura i que caiba na matriz
void histogram(int alturasHistograma[], int colunas, int comprimParaAltura[]) {
	int stack_top, width;
	stack<int> st;

	int i = 0;
	while (i < colunas) {
		if (st.empty() || alturasHistograma[st.top()] <= alturasHistograma[i]) {
			st.push(i++);
		} else {
			stack_top = alturasHistograma[st.top()];
			st.pop();
			width = i;

			if (!st.empty()) 
				width = i - st.top() - 1;

			if (comprimParaAltura[stack_top] < width) 
				comprimParaAltura[stack_top] = width;
		}
	}

	while (!st.empty()) {
		stack_top = alturasHistograma[st.top()];
		st.pop();
		width = i;

		if (!st.empty())
			width = i - st.top() - 1;

		if (comprimParaAltura[stack_top] < width)
			comprimParaAltura[stack_top] = width;
	}
}

bool fits(int c, int l, int comprimParaAltura[], int maxRectSize) {
	return (c <= maxRectSize and l <= comprimParaAltura[c]) or (l <= maxRectSize and c <= comprimParaAltura[l]);
}

void solve() {

	int n, m; cin >> n >> m; // dimensioes da matriz

	int mat[n][m]; memset(mat, 0, sizeof(mat));
	
	char str[m];
	f(i,0,n) {
		cin >> str;
		f(j,0,m) {
			if (str[j] == '.') 
				mat[i][j] = 1;
		}
	}

	int maxRectSize = min((int)500, max(n, m)); // dimensão maxima do retangulo (max(comprimentoMaximo, larguraMaxima))

	int comprimParaAltura[maxRectSize + 1]; 
	memset(comprimParaAltura, -1, sizeof(comprimParaAltura));

	int histogramaAux[m]; memset(histogramaAux, 0, sizeof(histogramaAux));

	f(i,0,n) {
		f(j,0,m) {
			histogramaAux[j] = (mat[i][j] ? 1 + histogramaAux[j] : 0);
		}
		histogram(histogramaAux, m, comprimParaAltura);
	}

    int comprimentoRetangulo, larguraRetangulo; cin >> comprimentoRetangulo >> larguraRetangulo;

    if(fits(comprimentoRetangulo, larguraRetangulo, comprimParaAltura, maxRectSize)) {
        /* retangulo de comprimento comprimentoRetangulo e largura larguraRetangulo cabe na matriz */
    }
}
