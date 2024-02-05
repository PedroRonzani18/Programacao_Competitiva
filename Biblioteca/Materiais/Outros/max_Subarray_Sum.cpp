// Maximum Subarray Sum
// Descricao: Retorna a soma maxima de um subarray de um vetor.
// Complexidade: O(n) onde n eh o tamanho do vetor
int maxSubarraySum(vector<int> x) {
    int best = 0, sum = 0;
    for (int k = 0; k < n; k++) {
        sum = max(x[k],sum+x[k]);
        best = max(best,sum);
    }
    return best;
}
