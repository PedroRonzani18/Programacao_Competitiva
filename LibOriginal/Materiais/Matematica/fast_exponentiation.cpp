const int mod = 1e9 + 7;

// Fast Exponentiation: retorna a^b % mod
// Quando usar: quando precisar calcular a^b % mod
int fexp(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
            ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}