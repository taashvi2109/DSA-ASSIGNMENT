#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;
    int n, x;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        q.push(x);
    }

    queue<int> first;
    int half = n / 2;

    for (int i = 0; i < half; i++) {
        first.push(q.front());
        q.pop();
    }

    while (!first.empty()) {
        q.push(first.front());
        first.pop();
        q.push(q.front());
        q.pop();
    }

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
}
