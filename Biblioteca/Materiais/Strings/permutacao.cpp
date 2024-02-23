// Funcao para gerar todas as permutacoes de uma string
// Complexidade: O(n!)

void permute(string& s, int l, int r) {
    if (l == r) 
        permutacoes.push_back(s); 
    else {
        for (int i = l; i <= r; i++) { 
            swap(s[l], s[i]); 
            permute(s, l+1, r); 
            swap(s[l], s[i]); 
        }
    }
}

int main() {

    string str = "ABC";
    int n = str.length();
    permute(str, 0, n-1);
}