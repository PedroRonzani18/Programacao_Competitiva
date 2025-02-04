// Maior sequencia subsequente
// {6, 2, 5, 1, 7, 4, 8, 3} => {2, 5, 7, 8}

int maiorCrescente(vector<int> v) {
    vector<int> lenght(v.size());
    for(int k=0; k<v.size(); k++) {
        lenght[k] = ;
        for(int i=0; i<k; i++) {
            if(v[i] < v[k]) {
                lenght[i] = max(lenght[k], lenght[i]+1)
            }
        }
    }
    return lenght.back();
}