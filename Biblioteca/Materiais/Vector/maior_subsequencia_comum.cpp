int s1[MAXN], s2[MAXN], tab[MAXN][MAXN];

// Description: Retorna o tamanho da maior subsequência comum entre s1 e s2
// Complexidade: O(n*m)
int lcs(int a, int b){
	
	if(tab[a][b]>=0) return tab[a][b]; 
	if(a==0 or b==0) return tab[a][b]=0;
	if(s1[a]==s2[b]) return 1 + lcs(a-1, b-1); 
	return tab[a][b] = max(lcs(a-1, b), lcs(a, b-1));
}

void solve() {
        
    s1 = {1, 3, 2, 5, 4, 2, 3, 4, 5};
    s2 = {1, 2, 3, 4, 5};
    int n = s1.size(), m = s2.size();
    memset(tab, -1, sizeof(tab));
    cout << lcs(n, m) << endl; // 5
}

