int n = 11, ans = 0, k = 3;

// Operacoes com bits
ans = n & k; // AND bit a bit
ans = n | k; // OR bit a bit
ans = n ^ k; // XOR bit a bit
ans = ~n;    // NOT bit a bit

// Operacoes com 2^k em O(1)
ans = n << k; // ans = n * 2^k
ans = n >> k; // ans = n / 2^k 

int j;

// Ativa j-esimo bit (0-based)
ans |= (1<<j);

// Desativa j-esimo bit (0-based)
ans &= (1<<j);

// Inverte j-esimo bit (0-based)
ans ^= (1<<j);

// checar se j-esimo bit esta ativo (0-based)
ans = n & (1<<j);

// Pegar valor do bit menos significativo | Retorna o maior divisor
ans = n & -n;

// Ligar todos on n bits
ans = (1<<n) - 1;

// Contar quantos 1's tem no binario de n
ans = __builtin_popcount(n);

// Contar quantos 0's tem no final do binario de n
ans = __builtin_ctz(n);