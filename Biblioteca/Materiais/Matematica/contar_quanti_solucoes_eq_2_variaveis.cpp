// Description: Dada uma equacao de 2 variaveis, calcudla quantas combinacoes {x,y} inteiras que resolvem essa equacao

// y = numerador / denominador
int numerador(int x) { return c - x; } // expressao do numerador
int denominador(int x) { return 2 * x + 1; } // expressao do denominador

int count2VariableIntegerEquationAnswers() {

    unordered_set<pair<int,int>, PairHash> ans; int lim = sqrt(c);
    for(int i=1; i<= lim; i++) {
        if (numerador(i) % denominador(i) == 0) {
            int x = i, y = numerador(i) / denominador(i);
            if(!ans.count({x,y}) and !ans.count({y,x}))
                ans.insert({x,y});
        }
    }

    return ans.size();
}