// Divisores - Contar
//
// Conta o numero de divisores de um numero baseadp no Smallest Prime Factor

vector<int> spf; // Smallest Prime Factor

void computeSpf(int n) {
    spf.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        spf[i] = i;
    }
    for (int i = 2; i * i <= n; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= n; j += i) {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}

int getDivisorCount(int x) {
    int cntDiv = 1;
    while (x > 1) {
        int p = spf[x];
        int cnt = 0;
        while (x % p == 0) {
            cnt++;
            x /= p;
        }
        cntDiv *= (cnt + 1);
    }
    return cntDiv;
}

void solve() {
	int n; // maior dos numeros a ser computado a listagem
	computeSpf(n); // gera os spf para todos ate n
	cout << getDivisorCount(n) << endl;
}
