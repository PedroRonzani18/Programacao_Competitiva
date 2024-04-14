// Description: Encontra um caminho euleriano em um grafo direcionado
// Complexidade: O(E)
// OBS: testar com bidirecionado / encontrar versao que aceita bidirecionado

int N;
vector<vi> adj; 
vi hierholzer(int s) {
    vi ans, idx(N, 0), st;
    st.push_back(s);
    while (!st.empty()) {
        int u = st.back();
        if (idx[u] < (int)adj[u].size()) { 
            st.push_back(adj[u][idx[u]]);
            ++idx[u];
        }
        else {
            ans.push_back(u);
            st.pop_back();
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}