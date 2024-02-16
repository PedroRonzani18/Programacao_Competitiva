#include <iostream>
#include <vector>

using namespace std;

int maxSuperLegalSubmatrix(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = (mat[i][j] + dp[i-1][j] <= dp[i-1][j-1] + dp[i][j-1]) ? dp[i-1][j] + dp[i][j-1] : 1;
            }
        }
    }
    int max_size = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            max_size = max(max_size, dp[i][j]);
        }
    }
    return max_size;
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> mat(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }
    int max_size = maxSuperLegalSubmatrix(mat);
    cout << max_size << endl;
    return 0;
}