void multiply(vector<int>& num, int x) {
   int carry = 0;
   for (int i = 0; i < num.size(); i++) {
       int prod = num[i] * x + carry;
       num[i] = prod % 10;
       carry = prod / 10;
   }
   while (carry != 0) {
       num.push_back(carry % 10);
       carry /= 10;
   }
}

// Calcula n!
// Complexidade: O(n) onde n eh o numero a ser fatorado
vector<int> factorial(int n) {
   vector<int> result;
   result.push_back(1);
   for (int i = 2; i <= n; i++) {
       multiply(result, i);
   }
   return result;
}
