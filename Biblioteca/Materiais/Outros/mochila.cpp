#define MAXN 1010 // maior peso / valor 
#define MAXS 1010 // maior capacidade mochila

int n, valor[MAXN], peso[MAXN], tab[MAXN][MAXS];

// Description: Retorna o maior valor que pode ser colocado na mochila
// Complexidade: O(n*capacidade)
int mochila(int obj=0, int aguenta=MAXS){
	
	if(tab[obj][aguenta]>=0) return tab[obj][aguenta];
	if(obj==n or !aguenta) return tab[obj][aguenta]=0;
	
	int nao_coloca = mochila(obj+1, aguenta);
	
	if(peso[obj] <= aguenta){
		int coloca = valor[obj] + mochila(obj+1, aguenta-peso[obj]);
		return tab[obj][aguenta] = max(coloca, nao_coloca);
	}
	
	return tab[obj][aguenta]=nao_coloca;
}

void solve() {
	cin >> n; // quantidade de elementos
	memset(tab, -1, sizeof(tab));
	for (int i = 0; i < n; i++) 
		cin >> valor[i] >> peso[i];
	cout << mochila() << endl; 
}

