#include <iostream>
#include <stack>
using namespace std;

bool match(char open, char close) {
    if (open == '(' && close == ')') return true;
    if (open == '{' && close == '}') return true;
    if (open == '[' && close == ']') return true;
    return false;
}

int main() {
    string exp;
    cin >> exp;

    stack<char> st;

    for (char c : exp) {
        if (c == '(' || c == '{' || c == '[')
            st.push(c);
        else if (c == ')' || c == '}' || c == ']') {
            if (st.empty() || !match(st.top(), c)) {
                cout << "Not Balanced";
                return 0;
            }
            st.pop();
        }
    }

    cout << (st.empty() ? "Balanced" : "Not Balanced");
}
