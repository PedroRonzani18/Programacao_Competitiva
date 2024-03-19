// Description: Converte uma expressao matematica infixa para posfixa
// Complexidade: O(n)
string infixToPostfix(string s) {
    stack<char> st;
    string res;
    for (char c : s) {
        if (isdigit(c))
            res += c;
        else if (c == '(')
            st.push(c);
        else if (c == ')') {
            while (st.top() != '(') {
                res += st.top();
                st.pop();
            }
            st.pop();
        } else {
            while (!st.empty() and st.top() != '(' and
                   (c == '+' or c == '-' or (st.top() == '*' or st.top() == '/'))) {
                res += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }
    return res;
}