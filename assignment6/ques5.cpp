#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* next;
    Node* prev;

    Node(char x) : data(x), next(NULL), prev(NULL) {}
};

class DoublyList {
    Node* head;

public:
    DoublyList() { head = NULL; }

    void insertEnd(char ch) {
        Node* n = new Node(ch);

        if (!head) { head = n; return; }

        Node* t = head;
        while (t->next) t = t->next;

        t->next = n;
        n->prev = t;
    }

    bool isPalindrome() {
        if (!head) return true;

        Node* left = head;
        Node* right = head;

        // Move right to the end
        while (right->next)
            right = right->next;

        // Check palindrome
        while (left != right && right->next != left) {
            if (left->data != right->data)
                return false;

            left = left->next;
            right = right->prev;
        }

        return true;
    }
};

int main() {
    DoublyList d;

    // Example: RADAR
    d.insertEnd('R');
    d.insertEnd('A');
    d.insertEnd('D');
    d.insertEnd('A');
    d.insertEnd('R');

    if (d.isPalindrome())
        cout << "Palindrome";
    else
        cout << "Not Palindrome";

    return 0;
}
