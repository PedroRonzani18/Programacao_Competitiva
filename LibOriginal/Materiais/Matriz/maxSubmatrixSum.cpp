// Description: Calcula a maior soma de uma submatriz MxN de uma matriz lxc
// Complexidade: O(l*c)

const int MAX = 1010; // 10^6 + 10

int mat[MAX][MAX];

int maxSubmatrixSum(int l, int c, int M, int N) {
	int dp[l+1][c+1];

	f(i,0,l+1) {
		dp[i][0] = 0;
		dp[0][i] = 0;
	}

	f(i,1,l+1) {
		f(j,1,c+1) {
			dp[i][j] =   dp[i-1][j] 
					   + dp[i][j-1]
					   - dp[i-1][j-1]
					   + mat[i][j];
		}
	}

	int ans = 0;
	f(i,M,l+1) {
		f(j,N,c+1) {
			int ponto = 
				  dp[i][j]
				- dp[i-M][j]
				- dp[i][j-N]
				+ dp[i-M][j-N];
			ans = max(ans, ponto);
		}
	}
	return ans;
}

void solve() {
	int l, c, M, N; cin >> l >> c >> M >> N;

	f(i,1,l+1) {
		f(j,1,c+1) {
			cin >> mat[i][j];
		}
	}

	int ans = maxSubmatrixSum(l, c, M, N);

	cout << ans << endl;
}