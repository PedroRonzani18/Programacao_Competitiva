// HEAP CRESCENTE {5,4,3,2,1}
priority_queue<int> pq; // max heap
    // maior elemento: 
    pq.top();

// HEAP DECRESCENTE {1,2,3,4,5}
priority_queue<int, vector<int>, greater<int>> pq; // min heap
    // menor elemento: 
    pq.top();

// REMOVER ELEMENTO
// Complexidade: O(n)
// Retorno: true se existe, false se não existe
pq.remove(x);

// INSERIR ELEMENTO
// Complexidade: O(log(n))
pq.push(x);

// REMOVER TOP
// Complexidade: O(log(n))
pq.pop();

// TAMANHO
// Complexidade: O(1)
pq.size();

// VAZIO
// Complexidade: O(1)
pq.empty();

// LIMPAR
// Complexidade: O(n)
pq.clear();

// ITERAR
// Complexidade: O(n)
for (auto x : pq) {}

// Ordenação por função customizada passada por parametro ao criar a pq
// Complexidade: O(n log(n))
auto cmp = [](int a, int b) { return a > b; };
priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);


