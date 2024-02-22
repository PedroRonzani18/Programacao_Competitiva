// Trocar elementos de lugar quando ha termos repetidos (ANAGRAMA)
int permutacaoComRepeticao(string s) {
    int n = s.size();
    int ans = fact(n);
    map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }
    for (auto [c, f] : freq) {
        ans /= fact(f);
    }
    return ans;
}