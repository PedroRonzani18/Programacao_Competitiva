vector<int> troco(vector<int> coins, int n) {
    int first[n];
    value[0] = 0;
    for(int x=1; x<=n; x++) {
        value[x] = INF;
        for(auto c : coins) {
            if(x-c => 0 and value[x-c] + 1 < value[x]) {
                value[x] = value[x-c]+1;
                first[x] = c;
            }
        }
    }

    vector<int> ans;
    while(n>0) {
        ans.push_back(first[n]);
        n -= first[n];
    }
    return ans;
}