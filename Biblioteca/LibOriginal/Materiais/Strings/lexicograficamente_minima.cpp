// Descricao: Retorna a menor rotacao lexicografica de uma string.
// Complexidade: O(n * log(n)) onde n eh o tamanho da string
string minLexRotation(string str) {
    int n = str.length();
 
    string arr[n], concat = str + str;
 
    for (int i = 0; i < n; i++)
        arr[i] = concat.substr(i, n);
 
    sort(arr, arr+n);
 
    return arr[0];
}
 
