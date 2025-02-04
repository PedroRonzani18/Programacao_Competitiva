// Gerar tabela verdade de uma expressão booleana
// Complexidade: O(2^n)

vector<vector<int>> tabelaVerdade; 
int indexTabela = 0;

void backtracking(int posicao, vector<int>& conj_bool) {
    
    if(posicao == conj_bool.size()) { // Se chegou ao fim da BST
        for(size_t i=0; i<conj_bool.size(); i++) {
            tabelaVerdade[indexTabela].push_back(conj_bool[i]);
        }
        indexTabela++;
        
    } else {
        conj_bool[posicao] = 1;
        backtracking(posicao+1,conj_bool);
        conj_bool[posicao] = 0;
        backtracking(posicao+1,conj_bool);
    }
}

int main() { 

    int n = 3;

    vector<int> linhaBool (n, false);
    tabelaVerdade.resize(pow(2,n));

    backtracking(0,linhaBool);
}