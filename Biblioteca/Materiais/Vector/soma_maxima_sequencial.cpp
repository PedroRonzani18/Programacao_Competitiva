// Description: Soma maxima sequencial de um vetor
// Complexidade: O(n)
int max_sum(vector<int> s) {
	
	int ans = 0, maior = 0;
	
	for(int i = 0; i < s.size(); i++) {
		maior = max(0,maior+s[i]);
		ans = max(resp,maior);
	}
	
	return ans;
}

void solve() {
    vector<int> v = {1,-3,5,-1,2,-1};
    cout << max_sum(v) << endl; // 6 = {5,-1,2}
}

