// Is Subset Sum (Iterativo)
//
// Verifica se a soma de 0 <= i <= n elementos iguala a sum
// Temporal: O(sum * n)
// Espacial: O(sum * n)

const int MAXN = 100;
const int MAXSUM = 5000;

bool isSubsetSum(vector<int>& v, int n, int sum) {
    f(i, 0, n + 1) { memo[i][0] = true; }
    f(j, 1, sum + 1) { memo[0][j] = false; }
    
    f(i, 1, n + 1) {
        f(j, 1, sum + 1) {
            if(j < v[i-1])
                memo[i][j] = memo[i-1][j];
            else
                memo[i][j] = memo[i-1][j] || memo[i-1][j- v[i-1]];
        }
    }
    return memo[n][sum];
}

void solve(int n, int sum) {
    
    vector<int> v(n);
	for(auto& x : n) cin >> x;
    
    cout << (isSubsetSum(v, n, k) ? "S" : "N") << endl;
}

