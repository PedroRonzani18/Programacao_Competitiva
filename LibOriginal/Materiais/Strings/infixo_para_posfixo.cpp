// Description: Converte uma expressao matematica infixa para posfixa
// Complexidade: O(n)
int prec(char c) {
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}
 
char associativity(char c) {
    if (c == '^')
        return 'R';
    return 'L'; 
}
 
string infixToPostfix(string s) {
    stack<char> st;
    string result;
 
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
 
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            result += c;
 
        else if (c == '(')
            st.push('(');
 
        else if (c == ')') {
            while (st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop(); // Pop '('
        }
 
        else {
            while (!st.empty() && prec(s[i]) < prec(st.top()) ||
                   !st.empty() && prec(s[i]) == prec(st.top()) &&
                   associativity(s[i]) == 'L') {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
 
    return result;
}