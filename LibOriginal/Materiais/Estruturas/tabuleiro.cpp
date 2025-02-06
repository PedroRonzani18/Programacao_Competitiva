// Description: Estrutura que simula um tabuleiro M x N, sem realmente criar uma matriz
//              Permite atribuir valores a linhas e colunas, e consultar a posição mais frequente
// Complexidade Atribuir: O(log(N))
// Complexidade Consulta: O(log(N))
// Complexidade verificar frequencia geral: O(N * log(N))
#define MAX_VAL 5 // maior valor que pode ser adicionado na matriz + 1

class BinTree {
    protected:
        vector<int> mBin;
    public:
        explicit BinTree(int n) { mBin = vector(n + 1, 0); }

        void add(int p, const int val) {
            for (auto size = mBin.size(); p < size; p += p & -p)
                mBin[p] += val;
        }

        int query(int p) {
            int sumToP {0};
            for (; p > 0; p -= p & -p)
                sumToP += mBin[p];
            return sumToP;
        }
};

class ReverseBinTree : public BinTree {
    public:
        explicit ReverseBinTree(int n) : BinTree(n) {};

        void add(int p, const int val) {
            BinTree::add(static_cast<int>(mBin.size()) - p, val);
        }

        int query(int p) {
            return BinTree::query(static_cast<int>(mBin.size()) - p);
        }
};

class Tabuleiro {
    public:
        explicit Tabuleiro(const int m, const int n, const int q) : mM(m), mN(n), mQ(q) {
            mLinhas = vector<pair<int, int8_t>>(m, {0, 0});
            mColunas = vector<pair<int, int8_t>>(n, {0, 0});

            mAtribuicoesLinhas = vector(MAX_VAL, ReverseBinTree(mQ)); // aARvore[51]
            mAtribuicoesColunas = vector(MAX_VAL, ReverseBinTree(mQ));
        }

        void atribuirLinha(const int x, const int8_t r) {
            mAtribuirFileira(x, r, mLinhas, mAtribuicoesLinhas);
        }

        void atribuirColuna(const int x, const int8_t r) {
            mAtribuirFileira(x, r, mColunas, mAtribuicoesColunas);
        }

        int maxPosLinha(const int x) {
            return mMaxPosFileira(x, mLinhas, mAtribuicoesColunas, mM);
        }

        int maxPosColuna(const int x) {
            return mMaxPosFileira(x, mColunas, mAtribuicoesLinhas, mN);
        }

        vector<int> frequenciaElementos() {

            vector<int> frequenciaGlobal(MAX_VAL, 0);
            for(int i=0; i<mM; i++) {
                vector<int> curr = frequenciaElementos(i, mAtribuicoesColunas);
                for(int j=0; j<MAX_VAL; j++)
                    frequenciaGlobal[j] += curr[j];
            }
            return frequenciaGlobal;
        }

    private:
        int mM, mN, mQ, mMoment {0};

        vector<ReverseBinTree> mAtribuicoesLinhas, mAtribuicoesColunas;
        vector<pair<int, int8_t>> mLinhas, mColunas;

        void mAtribuirFileira(const int x, const int8_t r, vector<pair<int, int8_t>>& fileiras,
                            vector<ReverseBinTree>& atribuicoes) {
            if (auto& [oldQ, oldR] = fileiras[x]; oldQ)
                atribuicoes[oldR].add(oldQ, -1);

            const int currentMoment = ++mMoment;
            fileiras[x].first = currentMoment;
            fileiras[x].second = r;
            atribuicoes[r].add(currentMoment, 1);
        }

        int mMaxPosFileira(const int x, const vector<pair<int, int8_t>>& fileiras, vector<ReverseBinTree>& atribuicoesPerpendiculares, const int& currM) const {
            auto [momentoAtribuicaoFileira, rFileira] = fileiras[x];

            vector<int> fileiraFrequencia(MAX_VAL, 0);
            fileiraFrequencia[rFileira] = currM;

            for (int8_t r {0}; r < MAX_VAL; ++r) {
                const int frequenciaR = atribuicoesPerpendiculares[r].query(momentoAtribuicaoFileira + 1);
                fileiraFrequencia[rFileira] -= frequenciaR;
                fileiraFrequencia[r] += frequenciaR;
            }

            return MAX_VAL - 1 - (max_element(fileiraFrequencia.crbegin(), fileiraFrequencia.crend()) - fileiraFrequencia.crbegin());
        }

        vector<int> frequenciaElementos(int x, vector<ReverseBinTree>& atribuicoesPerpendiculares) const {
            
            vector<int> fileiraFrequencia(MAX_VAL, 0);

            auto [momentoAtribuicaoFileira, rFileira] = mLinhas[x];

            fileiraFrequencia[rFileira] = mN;

            for (int8_t r {0}; r < MAX_VAL; ++r) {
                const int frequenciaR = atribuicoesPerpendiculares[r].query(momentoAtribuicaoFileira + 1);
                fileiraFrequencia[rFileira] -= frequenciaR;
                fileiraFrequencia[r] += frequenciaR;
            }

            return fileiraFrequencia;
        }

};

void solve() {

    int L, C, q; cin >> L >> C >> q;

    Tabuleiro tabuleiro(L, C, q);

    int linha = 0, coluna = 0, valor = 10; // linha e coluna sao 0 based
    tabuleiro.atribuirLinha(linha, static_cast<int8_t>(valor)); // f(i,0,C) matriz[linha][i] = valor
    tabuleiro.atribuirColuna(coluna, static_cast<int8_t>(valor)); // f(i,0,L) matriz[i][coluna] = valor

    // Freuencia de todos os elementos, de 0 a MAX_VAL-1
    vector<int> frequenciaGeral = tabuleiro.frequenciaElementos();

    int a = tabuleiro.maxPosLinha(linha); // retorna a posicao do elemento mais frequente na linha
    int b = tabuleiro.maxPosColuna(coluna); // retorna a posicao do elemento mais frequente na coluna
}