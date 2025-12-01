#include <iostream>
using namespace std;

// ---------------- DOUBLY NODE ----------------
class DNode {
public:
    int data;
    DNode* next;
    DNode* prev;
    DNode(int x) : data(x), next(NULL), prev(NULL) {}
};

// ---------------- DOUBLY LINKED LIST ----------------
class DoublyList {
    DNode* head;

public:
    DoublyList() { head = NULL; }

    void insertEnd(int val) {
        DNode* n = new DNode(val);
        if (!head) {
            head = n;
            return;
        }

        DNode* t = head;
        while (t->next) t = t->next;

        t->next = n;
        n->prev = t;
    }

    int size() {
        int count = 0;
        DNode* t = head;
        while (t) {
            count++;
            t = t->next;
        }
        return count;
    }
};

// ---------------- CIRCULAR NODE ----------------
class CNode {
public:
    int data;
    CNode* next;
    CNode(int x) : data(x), next(NULL) {}
};

// ---------------- CIRCULAR LINKED LIST ----------------
class CircularList {
    CNode* head;

public:
    CircularList() { head = NULL; }

    void insertEnd(int val) {
        CNode* n = new CNode(val);
        if (!head) {
            head = n;
            n->next = head;
            return;
        }

        CNode* t = head;
        while (t->next != head) t = t->next;

        t->next = n;
        n->next = head;
    }

    int size() {
        if (!head) return 0;

        int count = 0;
        CNode* t = head;

        do {
            count++;
            t = t->next;
        } while (t != head);

        return count;
    }
};

int main() {

    DoublyList D;
    D.insertEnd(10);
    D.insertEnd(20);
    D.insertEnd(30);

    cout << "Size of Doubly Linked List = " << D.size() << endl;

    CircularList C;
    C.insertEnd(5);
    C.insertEnd(15);
    C.insertEnd(25);
    C.insertEnd(35);

    cout << "Size of Circular Linked List = " << C.size() << endl;

    return 0;
}
