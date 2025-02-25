// Longest Common Subsequence 1 (LCS)
//
// Retrorna a LCS entre as string S e T.
// Armazena em memo[i][j] o LCS_SZ de s[i...n] e t[j...m].
// Implementacao recursiva
//
// Temporal: O(n*m)
// Espacial: O(n*m)

const int MAXN = 1e3+10;

int memo[MAXN][MAXN];

// Calcula tamanho do LCS recursivamente
int lcs_sz(string& s, string& t, int i, int j) {
	if(i == s.size() or j == t.size()) return 0;
	auto& ans = memo[i][j];
	if(~ans) return ans;
	if(s[i] == t[j])
		ans = 1 + lcs_sz(s,t,i+1, j+1);
	else
		ans = max(
				lcs_sz(s,t,i+1,j),
				lcs_sz(s,t,i,j+1)
			);
	return ans;
}

// Armazena em ans a LCS entre S e T
void lcs(string& ans, string& s, string& t, int i, int j) {
	if(i >= s.size() or j >= t.size()) return;
	if(s[i] == t[j]) {
		ans.push_back(s[i]);
		return lcs(ans, s, t, i+1, j+1);
	}
	if(lcs_sz(s,t,i+1,j) > lcs_sz(s,t,i,j+1)) return lcs(ans, s, t, i+1, j);
	return lcs(ans, s, t, i, j+1);
}

void solve() {

	string s, t; cin >> s >> t;
	
	memset(memo,-1, sizeof memo);

	string ans; lcs(ans, s, t, 0,0);
	cout << ans << endl;
}

