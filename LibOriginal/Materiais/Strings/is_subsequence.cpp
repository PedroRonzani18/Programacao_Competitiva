// Description: Verifica se a string s eh subsequencia da string t
// Complexidade Temporal: O(n)
// Complexidade Espacial: O(n)
bool isSubsequence(string& s, string& t) {
    queue<char> q;
    int cnt = 0;
    for (int i = 0; i < t.size(); i++) {
        q.push(t[i]);
    }
    int i = 0;
    while (!q.empty()) {
        if (s[i] == q.front()) {
            cnt++;
            i++;
        }
        q.pop();
    }

	return cnt == s.size();
}