// Retorna o tamanho da maior subsequência crescente de v
// Complexidade: O(n log(n))
int maiorSubCrescSize(vector<int> &v) {

    vector<int> pilha;
    for (int i = 0; i < v.size(); i++) {
        auto it = lower_bound(pilha.begin(), pilha.end(), v[i]);
        if (it == pilha.end())
            pilha.push_back(v[i]);
        else
            *it = v[i];
    }

    return pilha.size();
}

// Retorna a maior subsequência crescente de v
// Complexidade: O(n log(n))
vector<int> maiorSubCresc(vector<int> &v) {

    vector<int> pilha, resp;
    int pos[MAXN], pai[MAXN];
    for (int i = 0; i < v.size(); i++) {
        auto it = lower_bound(pilha.begin(), pilha.end(), v[i]);
        int p = it - pilha.begin();
        if (it == pilha.end())
            pilha.PB(v[i]);
        else
            *it = x;
        pos[p] = i;
        if (p == 0)
            pai[i] = -1; // seu pai será -1
        else
            pai[i] = pos[p - 1];
    }

    int p = pos[pilha.size() - 1];
    while (p >= 0) {
        resp.PB(v[p]);
        p = pai[p];
    }
    reverse(resp.begin(), resp.end());

    return resp;
}

void solve() {
    vector<int> v = {1, 3, 2, 5, 4, 2, 3, 4, 5};
    cout << maiorSubCrescSize(v) << endl // 5
    /****************************************/
    vector<int> ans = maiorSubCresc(v); // {1,2,3,4,5}
}
