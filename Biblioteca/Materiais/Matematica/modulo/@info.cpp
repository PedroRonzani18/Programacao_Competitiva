SOMA
(a + b) % m = ((a % m) + (b % m)) % m

SUBTRAÇÃO
(a - b) % m = ((a % m) - (b % m) + m) % m

MULTIPLICAÇÃO
(a * b) % m = ((a % m) * (b % m)) % m

DIVISÃO
(a / b) % m      = (a * b^-1) % m   
// se m eh primo = ((a % m) * (b^(m-2) % m)) % m. 
// else          = (a * modInverse(b, m)) % m

POTENCIA
(a ^ b) % m = ((a % m) ^ b) % m = modPow(a, b, m)
