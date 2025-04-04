vector<int> v;
    // Sort Crescente:
    sort(v.begin(), v.end());
    sort(all(v));

    // Sort Decrescente:
    sort(v.rbegin(), v.rend());
    sort(all(v), greater<int>());
 
    // Sort por uma função:
    auto cmp = [](int a, int b) { return a > b; }; // { 2, 3, 1 } -> { 3, 2, 1 }
    auto cmp = [](int a, int b) { return a < b; }; // { 2, 3, 1 } -> { 1, 2, 3 }
    sort(v.begin(), v.end(), cmp);
    sort(all(v), cmp);

    // Sort por uma função (comparação de pares):
    auto cmp = [](pair<int, int> a, pair<int, int> b) { return a.second > b.second; };

    // Sort parcial:
    partial_sort(v.begin(), v.begin() + n, v.end()); // sorta com n menos elementos
    partial_sort(v.rbegin(), v.rbegin() + n, s.rend()) // sorta com n maiores elementos

    // SORT VS SET
    * para um input com elementos distintos, sort é mais rápido que set    