// Conta quantos intervalos nao tem overlap ([a,b] e [b,c] nao geram)

bool cmp(const pair<int,int>& p1, const pair<int,int>& p2) {
    if(p1.second != p2.second) return p1.second < p2.second;
    return p1.first < p2.first;
}

int countNonOverlappingIntervals(vector<pair<int,int>> intervals) {
    sort(all(intervals), cmp);
    int firstTermino = intervals[0].second;
    int ans = 1;
    f(i,1,intervals.size()) {
        if(intervals[i].first >= firstTermino) {
            ans++;
            firstTermino = intervals[i].second;
        }
    }

    return ans;
}

