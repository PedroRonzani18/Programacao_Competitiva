// INICIALIZAR
string s; // string vazia
string s (n, c); // n cópias de c
string s (s); // cópia de s
string s (s, i, n); // cópia de s[i..i+n-1]

// SUBSTRING
// Complexidade: O(n)
s.substr(i, n); // substring de s[i..i+n-1]
s.substr(i, j - i + 1); // substring de s[i..j]

// TAMANHO
// Complexidade: O(1)
s.size(); // tamanho da string
s.empty(); // true se vazia, false se não vazia

// MODIFICAR
// Complexidade: O(n)
s.push_back(c); // adiciona c no final
s.pop_back(); // remove o último
s += t; // concatena t no final
s.insert(i, t); // insere t a partir da posição i
s.erase(i, n); // remove n caracteres a partir da posição i
s.replace(i, n, t); // substitui n caracteres a partir da posição i por t
s.swap(t); // troca o conteúdo com t

// COMPARAR
// Complexidade: O(n)
s == t; // igualdade
s != t; // diferença
s < t; // menor que
s > t; // maior que
s <= t; // menor ou igual
s >= t; // maior ou igual

// BUSCA
// Complexidade: O(n)
s.find(t); // posição da primeira ocorrência de t, ou string::npos se não existe
s.rfind(t); // posição da última ocorrência de t, ou string::npos se não existe
s.find_first_of(t); // posição da primeira ocorrência de um caractere de t, ou string::npos se não existe
s.find_last_of(t); // posição da última ocorrência de um caractere de t, ou string::npos se não existe
s.find_first_not_of(t); // posição do primeiro caractere que não está em t, ou string::npos se não existe
s.find_last_not_of(t); // posição do último caractere que não está em t, ou string::npos se não existe

// SUBSTITUIR
// Complexidade: O(n)
s.replace(i, n, t); // substitui n caracteres a partir da posição i por t
s.replace(s.begin() + i, s.begin() + i + n, t.begin(), t.end()); // substitui n caracteres a partir da posição i por t
s.replace(s.begin() + i, s.begin() + i + n, t); // substitui n caracteres a partir da posição i por t
s.replace(s.begin() + i, s.begin() + i + n, n, c); // substitui n caracteres a partir da posição i por n cópias de c

