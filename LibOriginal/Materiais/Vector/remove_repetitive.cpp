// Remove repetitive elements from a vector
// Complexity: O(n)
vector<int> removeRepetitive(const vector<int>& vec) {

    unordered_set<int> s;
    s.reserve(vec.size());

    vector<int> ans;

    for (int num : vec) {
        if (s.insert(num).second) 
            v.push_back(num);
    }

    return ans;
}

void solve() {
    vector<int> v = {1, 3, 2, 5, 4, 2, 3, 4, 5};
    vector<int> ans = removeRepetitive(v); // {1, 3, 2, 5, 4}
}