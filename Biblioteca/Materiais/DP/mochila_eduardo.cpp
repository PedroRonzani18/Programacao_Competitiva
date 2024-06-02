// Description: Implementação da mochila com reconstrução de solução
// Complexidade: O(n*capacidade)

int t[100][100];// Defina os tamanhos confome seu problema, pode usar vector

unordered_set<int> selecionados; // conjunto dos indices do itens que serão selecionados
int numItens;

// ps = pesos, vals = valores, fiz isso por legibilidade
int knapsack(int i, int cap, int ps[], int vals[]) {
    if(cap < 0) return -0x3f3f3f3f;
    if(i == numItens) return 0;
    if(t[i][cap] > -1) return t[i][cap];

    int x = knapsack(i + 1, cap, ps, vals);
    int y = knapsack(i + 1, cap - ps[i], ps, vals) + vals[i];
    return t[i][cap] = max(x, y);
}

// ps = pesos, vals = valores, fiz isso por legibilidade
void retrieve(int i, int cap, int ps[], int vals[]) {
    if(i == numItens) return;

    if(cap >= ps[i]) { // Dividi o if para legibilidade
        if(knapsack(i + 1, cap, ps, vals) < knapsack(i + 1, cap - ps[i], ps, vals) + vals[i]){
            selecionados.insert(i);
            return retrieve(i + 1, cap - ps[i], ps, vals);
        }
    }

    return retrieve(i + 1, cap, ps, vals);
}

int main() {
    memset(t, -1, sizeof t);

    int capacidade = 6;
    int pesos[] = {5, 4, 2}, valores[] = {500, 300, 250};
    numItens = 3;

    cout << knapsack(0, capacidade, pesos, valores) << endl;

    retrieve(0, 6, pesos, valores);
    for(auto i : selecionados) cout << i << ' ';
    cout << endl;
}