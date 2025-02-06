// Calcula o maior triângulo em um histograma
// Complexidade: O(n)
int maiorTrianguloEmHistograma(const vector<int>& histograma) {

	int n = histograma.size();
	vector<int> esquerda(n), direita(n);

    esquerda[0] = 1;
	f(i,1,n) {
        esquerda[i] = min(histograma[i], esquerda[i - 1] + 1);
    }

    direita[n - 1] = 1;
	rf(i,n-1,0) {
		direita[i] = min(histograma[i], direita[i + 1] + 1);
	}

    int ans = 0;
	f(i,0,n) {
		ans = max(ans, min(esquerda[i], direita[i]));
	}

    return ans;

}