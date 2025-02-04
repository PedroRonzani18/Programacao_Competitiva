// Description: Problema do livro caixa: retorna a expressao que resulta em f
// Complexidade: O(n*f)
// Explicacao: parecido com mochila => dados n numeros, dita se existe uma expressao que resulta em f, dado que cada numero pode ser positivo, negativo ou nao utilizado
/*
5 7
1 2 3 4 5
=> ?+??+
*/

int f=1, n=1, entrada[MAX];
map<pii, bool> memo;
bool positivo[MAX], negativo[MAX];

bool dp(int id, int soma) {

	if(id == n) return soma == f;
	if(memo.count({soma, id})) return memo[{soma,id}];

	bool pos = dp(id+1, soma+entrada[id]);
	bool neg = dp(id+1, soma-entrada[id]);

	if(pos and !neg) positivo[id] = true;
	else if(!pos and neg) negativo[id] = true;
	else if(pos and neg) positivo[id] = negativo[id] = true;
	return memo[{soma,id}] = (pos or neg);
}

void solve() {

    cin>> n >> f;
	memo.clear();

	f(i,0,n) {
		positivo[i] = negativo[i] = false;
		cin >> entrada[i];
	}

	bool ans = dp(0,0);

	if(!ans) cout << "*";
	else {
		f(i,0,n) {
			bool pos = positivo[i], neg = negativo[i];
			if(pos and neg) cout << "?";
			else if(pos) cout << "+";
			else cout << "-";
		}
	}
}
