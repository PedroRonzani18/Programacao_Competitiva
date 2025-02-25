// Knapsack tradicional
//
// O(n * cap)

const int MAXN = 110;
const int MAXW = 1e5+10;

int n, memo[MAXN][MAXW];
int v[MAXN], w[MAXN];
int pego[MAXN] = {0};

// Retorna o lucro maximo 
int dp(int id, int cap) {
	if(cap < 0) return -LLINF;
	if(id == n or cap == 0) return 0;
	int &ans = memo[id][cap];
	if(~ans) return ans;
	return ans = max(dp(id+1, cap), dp(id+1, cap-w[id]) + v[id]);
}

// Armazena em pego os itens pegos 
void recuperar(int id, int cap) {
	if(id >= n) return;
	if(dp(id+1, cap-w[id]) + v[id] > dp(id+1, cap)) { // se pegar eh otimo
		pego[id] = true;
		recuperar(id+1, cap-w[id]);
	} else { // nao pegar eh otimo
		pego[id] = false;
		recuperar(id+1, cap);
	}
}


void solve() {

	int cap; cin >> n >> cap;
	memset(memo, -1, sizeof memo);

	f(i,0,n) { cin >> w[i] >> v[i]; }

	int lucro_max = dp(0, cap);

	recuperar(0, cap);
	
	int lucro = 0, peso = 0;
	f(i,0,n) {
		if(pego[i]) {
			lucro += v[i];
			peso += w[i];
		}
	}
	
	assert(lucro_max == lucro and peso <= cap);
}
