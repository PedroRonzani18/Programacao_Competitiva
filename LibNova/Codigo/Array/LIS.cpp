// Longest Increasing Subsequence
//
// Retorna a mauir subsequencia crescente dentro de um vetor
// O(n logn)
vector<int> lis(vector<int>& arr) {
    vector<int> subseq;
    for(int& x : arr) {
        auto it = lower_bound(subseq.begin(), subseq.end(), x);
        if (it == subseq.end()) subseq.push_back(x);
        else *it = x;
    }
    return subseq;
}
