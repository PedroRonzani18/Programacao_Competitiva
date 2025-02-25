// Knapsack tradicional
//
// O(n * cap)

const int MAXN = 110;
const int MAXW = 1e5+10;

int n, memo[MAXN][MAXW];
int v[MAXN], w[MAXN];

int dp(int id, int cap) {
	if(cap < 0) return -LLINF;
	if(id == n or cap == 0) return 0;
	int &ans = memo[id][cap];
	if(~ans) return ans;
	return ans = max(dp(id+1, cap), dp(id+1, cap-w[id]) + v[id]);
}

void solve() {

	int cap; cin >> n >> cap;
	memset(memo, -1, sizeof memo);

	f(i,0,n) { cin >> w[i] >> v[i]; }

	cout << dp(0, cap) << endl; 
}
