unordered_map<char, int> precedence = {{'|', 1}, {'.', 2}, {'>', 3}, {'<', 3}, {'=', 3}, {'#', 3}, {'+', 4}, {'-', 4}, {'*', 5}, {'/', 5}, {'^', 6}};
string ops = "+-*/^><=#.|";

bool isOp(char a) {
    return ops.find(a) != string::npos;
}

bool checkIfSyntaxError(const string &str) {
    int len = str.size();
    stack<char> pilha;
    for (int i = 0; i < len; i++) {
        if (isOp(str[i])) {
            if (i + 1 == len || i == 0) return true;
        	if (!isalnum(str[i - 1]) and str[i - 1] != ')') return true;
            if (!isalnum(str[i + 1]) and str[i + 1] != '(') return true;
            while (!pilha.empty() and pilha.top() != '(' and precedence[pilha.top()] >= precedence[str[i]]) {
                pilha.pop();
            }
            pilha.push(str[i]);
        }
        else if (str[i] == '(') {
            if (i > 0 and (isalnum(str[i - 1]) || str[i - 1] == ')')) return true;
            pilha.push('(');
        }
        else if (str[i] == ')') {
            if (i > 0 and str[i - 1] == '(') return true;
            if (pilha.empty()) {
                return true;
            }
            while (!pilha.empty() and pilha.top() != '(') {
                pilha.pop();
                if (pilha.empty()) {
                    return true;
                }
            }
            if (!pilha.empty()) pilha.pop();
        }
        else if (isalnum(str[i])) {
            if (i > 0 and isalnum(str[i - 1]) and !isOp(str[i - 1]) and str[i - 1] != '(') return true;
        }
    }
    while (!pilha.empty()) {
        if (pilha.top() == '(') {
            return true;
        }
        pilha.pop();
    }
    return false;
}

bool checkIfLexicalError(const string &str) {
    for (char ch : str)
        if (!isalnum(ch) and !isOp(ch) and ch != '(' and ch != ')') 
            return true;
    return false;
}

void solve() {
    string str; cin >> str;
    if (checkIfLexicalError(str)) 
        cout << "Lexical Error!" << endl;
    else if (checkIfSyntaxError(str)) 
        cout << "Syntax Error!" << endl;
}

