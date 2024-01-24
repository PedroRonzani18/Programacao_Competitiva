#include <iostream>
#include <vector>

using namespace std;

vector<int> multiply(const vector<int>& num, int multiplier) {
    vector<int> result;
    int carry = 0;

    for (size_t i = 0; i < num.size(); ++i) {
        int product = num[i] * multiplier + carry;
        result.push_back(product % 10);
        carry = product / 10;
    }

    while (carry) {
        result.push_back(carry % 10);
        carry /= 10;
    }

    return result;
}

vector<int> factorial(int n) {
    vector<int> result;
    result.push_back(1);

    for (int i = 2; i <= n; ++i) {
        result = multiply(result, i);
    }

    reverse(result.begin(), result.end());
    return result;
}
