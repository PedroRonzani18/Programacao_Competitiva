// Given the number of cities 3 <= n <= 50, available time 1 <= t <= 1000, and two n x n matrices (one gives travel times and another gives tolls between two cities), choose a route from the port city (vertex 0) in such a way that the fishmonger has to pay as little tolls as possible to arrive at the market city (vertex n-1) within a certain time t

// Cada estado eh um vertice da DAG (node, tempoRestante)

pii dp(int cur, int t_left) { 
    if (t_left < 0) return {INF, INF}; 
    if (cur == n-1) return {0, 0}; 
    if (memo[cur][t_left] != {-1, -1}) return memo[cur][t_left];
    pii ans = {INF, INF};
    for (int X = 0; X < n; ++X)
    if (cur != X) {
        auto &[tollpaid, timeneeded] = dp(X, t_left-travelTime[cur][X]);
        if (tollpaid+toll[cur][X] < ans.first) { 
        ans.first = tollpaid+toll[cur][X];
        ans.second = timeneeded+travelTime[cur][X];
        }
    }
    return memo[cur][t_left] = ans;
}