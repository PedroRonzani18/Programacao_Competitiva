// Função para calcular o produto vetorial de dois vetores
int cross_product(const pair<int, int>& o, const pair<int, int>& a, const pair<int, int>& b) {
    return (a.first - o.first) * (b.second - o.second) - (a.second - o.second) * (b.first - o.first);
}

// Função para encontrar o ponto mais baixo (esquerda mais baixo)
pair<int, int> find_lowest_point(const vector<pair<int, int>>& points) {
    pair<int, int> lowest = points[0];
    for (const auto& point : points) {
        if (point.second < lowest.second || (point.second == lowest.second && point.first < lowest.first)) {
            lowest = point;
        }
    }
    return lowest;
}

// Função para ordenar pontos por ângulo polar em relação ao ponto mais baixo
bool compare(const pair<int, int>& a, const pair<int, int>& b, const pair<int, int>& lowest_point) {
    int cross = cross_product(lowest_point, a, b);
    if (cross != 0) {
        return cross > 0;
    }
    return (a.first != b.first) ? (a.first < b.first) : (a.second < b.second);
}

// Função para encontrar o envoltório convexo usando o algoritmo de Varredura de Graham
vector<pair<int, int>> convex_hull(vector<pair<int, int>>& points) {
    vector<pair<int, int>> convex_polygon;
    
    if (points.size() < 3) return convex_polygon;
    
    pair<int, int> lowest_point = find_lowest_point(points);
    sort(points.begin(), points.end(), [&lowest_point](const pair<int, int>& a, const pair<int, int>& b) {
        return compare(a, b, lowest_point);
    });
    
    convex_polygon.push_back(points[0]);
    convex_polygon.push_back(points[1]);
    
    for (int i = 2; i < points.size(); ++i) {
        while (convex_polygon.size() >= 2 && cross_product(convex_polygon[convex_polygon.size() - 2], convex_polygon.back(), points[i]) <= 0) {
            convex_polygon.pop_back();
        }
        convex_polygon.push_back(points[i]);
    }
    
    return convex_polygon;
}

void solve() {
    int n, turma = 0;


        vector<pair<int, int>> points(n);
        for (int i = 0; i < n; ++i) {
            cin >> points[i].first >> points[i].second; // x y 
        }
        
        vector<pair<int, int>> convex_polygon = convex_hull(points);
        int num_vertices = convex_polygon.size();

        cout << num_vertices << endl; // qnt de vertices , se quiser os pontos so usar o vi convex_polygon

        cout << endl;    
}
