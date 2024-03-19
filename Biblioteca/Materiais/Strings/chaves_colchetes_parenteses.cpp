// Description: Verifica se s tem uma sequência valida de {}, [] e ()
// Complexidade: O(n)
bool brackets(string s) {
    stack<char> st;

    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else {
            if (st.empty()) return false;
            if (c == ')' and st.top() != '(') return false;
            if (c == ']' and st.top() != '[') return false;
            if (c == '}' and st.top() != '{') return false;
            st.pop();
        }
    }

    return st.empty();
}