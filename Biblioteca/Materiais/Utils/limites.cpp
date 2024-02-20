// LIMITES DE REPRESENTACAO DE DADOS    

       tipo     | bits |         minimo .. maximo        | precisao decim.
----------------+------+---------------------------------+----------------
char            |   8  |              0 .. 127           |       2
signed char     |   8  |           -128 .. 127           |       2 
unsigned char   |   8  |              0 .. 255           |       2 
short           |  16  |        -32.768 .. 32.767        |       4
unsigned short  |  16  |              0 .. 65.535        |       4 
int             |  32  |      -2 x 10^9 .. 2 x 10^9      |       9
unsigned int    |  32  |              0 .. 4 x 10^9      |       9 
int64_t         |  64  |     -9 x 10^18 .. 9 x 10^18     |      18
uint64_t        |  64  |              0 .. 18 x 10^18    |      19
float           |  32  |   1.2 x 10^-38 .. 3.4 x 10^38   |      6-9
double          |  64  |  2.2 x 10^-308 .. 1.8 x 10^308  |     15-17
long double     |  80  | 3.4 x 10^-4932 .. 1.1 x 10^4932 |     18-19
BigInt/Dec(java)     1 x 10^-2147483648 .. 1 x 10^2147483647 | 0

// LIMITES DE MEMORIA

1MB = 1,048,576 bool
1MB =   524,288 char
1MB =   262,144 int32_t
1MB =   131,072 int64_t
1MB =    65,536 float
1MB =    32,768 double
1MB =    16,384 long double
1MB =    16,384 BigInteger / BigDecimal

// ESTOURAR TEMPO

imput size    | complexidade para 1 s
-----------------+--------------------
 [10,11]      | O(n!), O(n^6) 
 [15,18]      | O(2^n * n^2)
 [18, 22]     | O(2^n * n)
 ... 100      | O(n^4)
 ... 400      | O(n^3)
 ... 2*10^3   | O(n^2 * log n)
 ... 5*10^4   | O(n^2)
 ... 10^5     | O(n^2 log n)
 ... 10^6     | O(n log n)
 ... 10^7     | O(n log log n)
 ... 10^8     | O(n), O(log n), O(1)


// FATORIAL

12! =               479.001.600 [limite do (u)int] 
20! = 2.432.902.008.176.640.000 [limite do (u)int64_t]