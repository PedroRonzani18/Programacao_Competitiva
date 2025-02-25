// Exemplo Sapo
//
// There are N stones, numbered 1,2,...,N. 
// For each i (1<=i<=N), the height of Stone i is hi.
// There is a frog who is initially on Stone 1. 
// He will repeat the following action some number of times to reach Stone N:
// If the frog is currently on Stone i, jump to one of the following: Stone i+1,i+2,...,i+K. Here, a cost of|hi - hj| is incurred, wherej is the stone to land on.
// Find the minimum possible total cost incurred before the frog reaches Stone N.

int n, k;

// Top Down
int dp(int i) {
	if(i == 0) return 0;
	auto& ans = memo[i];
	if(~ans) return ans;

	int ret = INF;
	f(j, max(0ll,i-k), i)
		ret = min(ret, dp(j) + abs(h[j] - h[i]));

	return ans = ret;
}

// Bootom Up
int dp_2(int x) {
	
	memo[0] = 0;
	f(i,1,x) {
		int best = INF;
		f(j, max(0ll, i-k), i) {
			best = min(best, memo[j] + abs(h[i] - h[j]));
		}
		memo[i] = best;
	}

	return memo[x-1];
}

void solve() {
	cin >> n >> k;
	f(i,0,n) cin >> h[i];
	cout << dp(n-1) << endl;
}
