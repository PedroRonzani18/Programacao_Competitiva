// Descricao: Implementacao de operacoes com numeros grandes
// Complexidade: O(n * m), n = tamanho do primeiro numero, m = tamanho do segundo numero

void normalize(vector<int>& num) {
    int carry = 0;
    for (int i = 0; i < num.size(); ++i) {
        num[i] += carry;
        carry = num[i] / 10;
        num[i] %= 10;
    }

    while (carry > 0) {
        num.push_back(carry % 10);
        carry /= 10;
    }
}


pair<int, vector<int>> bigSum(const pair<int, vector<int>>& a, const pair<int, vector<int>>& b) {
    if (a.first == b.first) {
        vector<int> result(max(a.second.size(), b.second.size()), 0);
        transform(a.second.begin(), a.second.end(), b.second.begin(), result.begin(), plus<int>());
        normalize(result);
        return {a.first, result};
    } else {
        vector<int> result(max(a.second.size(), b.second.size()), 0);
        transform(a.second.begin(), a.second.end(), b.second.begin(), result.begin(), minus<int>());
        normalize(result);
        return {a.first, result};
    }
}

pair<int, vector<int>> bigSub(const pair<int, vector<int>>& a, const pair<int, vector<int>>& b) {
    return bigSum(a, {-b.first, b.second});
}

pair<int, vector<int>> bigMult(const pair<int, vector<int>>& a, const pair<int, vector<int>>& b) {
    vector<int> result(a.second.size() + b.second.size(), 0);

    for (int i = 0; i < a.second.size(); ++i) {
        for (int j = 0; j < b.second.size(); ++j) {
            result[i + j] += a.second[i] * b.second[j];
        }
    }

    normalize(result);
    return {a.first * b.first, result};
}


void printNumber(const pair<int, vector<int>>& num) {
    if (num.first == -1) {
        cout << '-';
    }

    for (auto it = num.second.rbegin(); it != num.second.rend(); ++it) {
        cout << *it;
    }
    cout << endl;
}

int main() {

    pair<int, vector<int>> num1 = {1, {1, 2, 3}};  // Representing +321
    pair<int, vector<int>> num2 = {-1, {4, 5, 6}};  // Representing -654

    cout << "Sum: "; printNumber(bigSum(num1, num2););
    cout << "Difference: "; printNumber(bigSub(num1, num2););
    cout << "Product: "; printNumber(bigMult(num1, num2););

}
