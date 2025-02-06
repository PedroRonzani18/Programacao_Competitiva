// Description: Calcula a potencia de uma matriz quadrada A elevada a um expoente n

int MOD;
const int MAX_N = 2;

struct Matrix { int mat[MAX_N][MAX_N]; };

int mod(int a, int m) { return ((a%m)+m) % m; }

Matrix matMul(Matrix a, Matrix b) {
    Matrix ans;
    for (int i = 0; i < MAX_N; ++i)
    for (int j = 0; j < MAX_N; ++j)
    ans.mat[i][j] = 0;

    for (int i = 0; i < MAX_N; ++i)
        for (int k = 0; k < MAX_N; ++k) {
            if (a.mat[i][k] == 0) continue;
            for (int j = 0; j < MAX_N; ++j) {
                ans.mat[i][j] += mod(a.mat[i][k], MOD) * mod(b.mat[k][j], MOD);
                ans.mat[i][j] = mod(ans.mat[i][j], MOD); 
                }
        }
    return ans;
}

Matrix matPow(Matrix base, int p) {
    Matrix ans;
    for (int i = 0; i < MAX_N; ++i)
    for (int j = 0; j < MAX_N; ++j)
    ans.mat[i][j] = (i == j);
    while (p) {
        if (p&1)
        ans = matMul(ans, base);
        base = matMul(base, base);
        p >>= 1;
    }
    return ans;
}

void solve() {

}