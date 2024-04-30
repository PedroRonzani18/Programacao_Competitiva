// Description: Encontra o comprimento da maior usbstring em comum entre 2 strings
// Complexidade Temporal: O(n * m)
// Complexidade Espacial: O(min(m,n))
int LCSubStr(string s, string t, int n, int m)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int ans = 0;
 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > ans)
                    ans = dp[i][j];
            }
            else
                dp[i][j] = 0;
        }
    }
    return ans;
}

void solve() {
    string x, y; cin >> x >> y;
	cout << LCSubStr(x, y, x.size(), y.size()) << endl;
}