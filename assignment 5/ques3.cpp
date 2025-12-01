#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

class LinkedList {
    Node* head;
public:
    LinkedList() { head = NULL; }

    void insertEnd(int val) {
        Node* n = new Node(val);
        if (!head) { head = n; return; }
        Node* t = head;
        while (t->next) t = t->next;
        t->next = n;
    }

    int findMiddle() {
        if (!head) return -1;

        Node* slow = head;
        Node* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow->data;
    }
};

int main() {
    LinkedList l;
    l.insertEnd(1);
    l.insertEnd(2);
    l.insertEnd(3);
    l.insertEnd(4);
    l.insertEnd(5);

    cout << "Middle Element: " << l.findMiddle() << endl;
}
