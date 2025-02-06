// Description: Problema da mochila 0-1: retorna o valor maximo que pode ser carregado
// Complexidade: O(n*capacidade)

const int MAX_QNT_OBJETOS = 60; // 50 + 10
const int MAX_PESO_OBJETO = 1010; // 1000 + 10

int n, memo[MAX_QNT_OBJETOS][MAX_PESO_OBJETO];
vi valor, peso;

int mochila(int id, int remW) {
	if ((id == n) || (remW == 0)) return 0;
	int &ans = memo[id][remW];
	if (ans != -1) return ans;
	if (peso[id] > remW) return ans = mochila(id+1, remW);
	return ans = max(mochila(id+1, remW), valor[id]+mochila(id+1, remW-peso[id]));
}

void solve() {

	memset(memo, -1, sizeof memo);

	int capacidadeMochila; cin >> capacidadeMochila;
	
	f(i,0,capacidadeMochila) { memo[0][i] = 0; } // testar com e sem essa linha

	cin >> n;

	valor.assign(n, 0);
	peso.assign(n, 0);

	f(i,0,n) {
	  cin >> peso[i] >> valor[i];
	}
	
	cout << mochila(0, capacidadeMochila) << endl;
}