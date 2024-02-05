unordered_map<int, int> memo;

// Factorial
// Complexidade: O(n), onde n eh o numero a ser fatorado
int factorial(int n) {
    if (n == 0 || n == 1)  return 1;
    if (memo.find(n) != memo.end()) return memo[n];
    return memo[n] = n * factorial(n - 1);
}