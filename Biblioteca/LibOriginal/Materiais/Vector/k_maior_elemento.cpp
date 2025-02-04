// Description: Encontra o k-ésimo maior elemento de um vetor
// Complexidade: O(n)

int Partition(vector<int>& A, int l, int r) {
    int p = A[l];
    int m = l;
    for (int k = l+1; k <= r; ++k) {
        if (A[k] < p) { 
            ++m;
            swap(A[k], A[m]);
        } 
    }
    swap(A[l], A[m]);
    return m;
}

int RandPartition(vector<int>& A, int l, int r) {
    int p = l + rand() % (r-l+1);
    swap(A[l], A[p]);
    return Partition(A, l, r);
}

int QuickSelect(vector<int>& A, int l, int r, int k) {
    if (l == r) return A[l];
    int q = RandPartition(A, l, r);
    if (q+1 == k)
        return A[q];
    else if (q+1 > k)
        return QuickSelect(A, l, q-1, k);
    else
        return QuickSelect(A, q+1, r, k);
}

void solve() {
    vector<int> A = { 2, 8, 7, 1, 5, 4, 6, 3 };
    int k = 1;
    cout << QuickSelect(A, 0, A.size()-1, k) << endl;
}