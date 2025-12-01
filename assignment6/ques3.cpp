#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

class CircularList {
    Node* head;

public:
    CircularList() { head = NULL; }

    void insertEnd(int val) {
        Node* n = new Node(val);
        if (!head) {
            head = n;
            n->next = head;
            return;
        }
        Node* t = head;
        while (t->next != head) t = t->next;
        t->next = n;
        n->next = head;
    }

    void display() {
        if (!head) return;
        Node* t = head;
        do {
            cout << t->data << " ";
            t = t->next;
        } while (t != head);

        cout << head->data;  // repeat head
    }
};

int main() {
    CircularList c;
    c.insertEnd(20);
    c.insertEnd(100);
    c.insertEnd(40);
    c.insertEnd(80);
    c.insertEnd(60);

    c.display();
}
