// INICIALIZAR
vector<int> v (n); // n cópias de 0
vector<int> v (n, v); // n cópias de v

// PUSH_BACK    
// Complexidade: O(1) amortizado (O(n) se realocar)
v.push_back(x);

// REMOVER
// Complexidade: O(n)
v.erase(v.begin() + i);

// INSERIR
// Complexidade: O(n)
v.insert(v.begin() + i, x);

// ORDENAR
// Complexidade: O(n log(n))
sort(v.begin(), v.end());
sort(all(v));

// BUSCA BINARIA
// Complexidade: O(log(n))
// Retorno: true se existe, false se não existe
binary_search(v.begin(), v.end(), x);

// FIND
// Complexidade: O(n)
// Retorno: iterador para o elemento, v.end() se não existe
find(v.begin(), v.end(), x);

// CONTAR
// Complexidade: O(n)
// Retorno: número de ocorrências
count(v.begin(), v.end(), x);