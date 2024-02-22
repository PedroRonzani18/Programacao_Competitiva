// Checa se um número é ímpar
#define isOdd(a) (a & 1) 

// Multiplica a por 2^b
#define mult2ToTheN(a, b) (a << b) 

// Divide a por 2^b
#define div2ToTheN(a, b) (a >> b) 

// 2^b
#define twoToTheN(b) (1 << b)

// Retorna -1 se n < 0, 0 se n = 0 e 1 se n > 0
#define sig(a) ((a >> 31) | -(a >> 31)) 

// Retorna o maior divisor (potencia de 2) de n 
#define greatest2powDivisorOf(a) (a & -a)
