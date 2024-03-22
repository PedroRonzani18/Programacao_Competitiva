// Description: Determina se um grafo eh bipartido ou nao
// Complexidade: O(V+E)

vector<vi> AL;

bool bipartido(int n) {

    int s = 0;
    queue<int> q; q.push(s);

    vi color(n, INF); color[s] = 0;
    bool ans = true; 
    while (!q.empty() && ans) { 
        int u = q.front(); q.pop();

        for (auto &v : AL[u]) {
            if (color[v] == INF) {                            
                color[v] = 1 - color[u]; 
                q.push(v);
            }
            else if (color[v] == color[u]) {                        
                ans = false; 
                break;               
            }
        }
    }

    return ans;
}

void solve() {

    int n, edg; cin >> n >> edg;
    AL.resize(n, vi());

    while(edg--) {
        int a, b; cin >> a >> b;
        AL[a].push_back(b);
        AL[b].push_back(a);
    }

    cout << bipartido(n) << endl;
}