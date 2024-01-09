#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<vector<int>> adj_list;
vector<int> C;
vector<int> parent;
vector<int> rank_set;

int find(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

void unionSet(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
        if (rank_set[rootX] < rank_set[rootY])
            swap(rootX, rootY);
        parent[rootY] = rootX;
        if (rank_set[rootX] == rank_set[rootY])
            rank_set[rootX]++;
    }
}

void dfs(int node, vector<int>& count, unordered_set<int>& visited) {
    visited.insert(node);
    for (int neighbor : adj_list[node]) {
        if (visited.find(neighbor) == visited.end()) {
            count[node]++;
            dfs(neighbor, count, visited);
        }
    }
}

int main() {
    int N;
    cin >> N;

    C.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> C[i];
    }

    adj_list.resize(N);
    parent.resize(N);
    rank_set.assign(N, 0);

    for (int i = 0; i < N; ++i) {
        parent[i] = i;
    }

    for (int i = 0; i < N - 1; ++i) {
        int A, B;
        cin >> A >> B;
        A--; // Convert to 0-based indexing
        B--; // Convert to 0-based indexing
        adj_list[A].push_back(B);
        adj_list[B].push_back(A);
    }

    vector<int> count(N, 0);
    unordered_set<int> visited;

    for (int i = 0; i < N; ++i) {
        if (visited.find(i) == visited.end()) {
            dfs(i, count, visited);
        }
    }

    unordered_map<int, long long> sum;
    for (int i = 0; i < N; ++i) {
        int root = find(i);
        int num = C[i];
        sum[root] += count[i];
        sum[root] -= sum[num]; // Adjust sum[root] by subtracting sum[num]
    }

    long long totalSum = 0;
    for (auto &s : sum) {
        totalSum += s.second;
    }

    cout << totalSum << endl;

    return 0;
}
