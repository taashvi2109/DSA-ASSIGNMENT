#include <iostream>
#include <string>
using namespace std;

class Stack {
    char arr[1000];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(char c) {
        arr[++top] = c;
    }

    char pop() {
        return arr[top--];
    }
};

int main() {
    string s, reversed = "";
    cin >> s;

    Stack st;

    for (char c : s)
        st.push(c);

    while (reversed.size() != s.size())
        reversed += st.pop();

    cout << reversed;
}
