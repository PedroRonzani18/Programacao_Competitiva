// Descricao: Funcao que verifica se uma string eh um palindromo.
// Complexidade: O(n) onde n eh o tamanho da string.
bool isPalindrome(string str) {
    for (int i = 0; i < str.length() / 2; i++) {
        if (str[i] != str[str.length() - i - 1]) {
            return false;
        }
    }
    return true;
}