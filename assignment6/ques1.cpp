#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
    Node(int x) : data(x), prev(NULL), next(NULL) {}
};

class DoublyList {
    Node* head;

public:
    DoublyList() { head = NULL; }

    // Insert at beginning
    void insertBeg(int val) {
        Node* n = new Node(val);
        if (head) {
            n->next = head;
            head->prev = n;
        }
        head = n;
    }

    // Insert at end
    void insertEnd(int val) {
        Node* n = new Node(val);
        if (!head) { head = n; return; }

        Node* t = head;
        while (t->next) t = t->next;

        t->next = n;
        n->prev = t;
    }

    // Insert before a specific key
    void insertBefore(int key, int val) {
        if (!head) return;

        if (head->data == key) { insertBeg(val); return; }

        Node* t = head;
        while (t && t->data != key) t = t->next;
        if (!t) return;

        Node* n = new Node(val);
        n->next = t;
        n->prev = t->prev;
        t->prev->next = n;
        t->prev = n;
    }

    // Insert after a specific key
    void insertAfter(int key, int val) {
        Node* t = head;
        while (t && t->data != key) t = t->next;
        if (!t) return;

        Node* n = new Node(val);
        n->next = t->next;
        n->prev = t;

        if (t->next) t->next->prev = n;
        t->next = n;
    }

    // Delete a specific node
    void deleteNode(int key) {
        if (!head) return;

        if (head->data == key) {
            Node* t = head;
            head = head->next;
            if (head) head->prev = NULL;
            delete t;
            return;
        }

        Node* t = head;
        while (t && t->data != key) t = t->next;
        if (!t) return;

        if (t->next) t->next->prev = t->prev;
        if (t->prev) t->prev->next = t->next;

        delete t;
    }

    // Search a node
    int search(int key) {
        Node* t = head;
        int pos = 1;
        while (t) {
            if (t->data == key) return pos;
            t = t->next;
            pos++;
        }
        return -1;
    }

    void display() {
        Node* t = head;
        while (t) {
            cout << t->data << " ";
            t = t->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyList d;
    int ch, val, key;

    while (true) {
        cout << "\nDOUBLY LINKED LIST MENU\n";
        cout << "1. Insert at Beginning\n2. Insert at End\n3. Insert Before Key\n4. Insert After Key\n";
        cout << "5. Delete Node\n6. Search\n7. Display\n8. Exit\n";
        cin >> ch;

        switch (ch) {
        case 1: cin >> val; d.insertBeg(val); break;
        case 2: cin >> val; d.insertEnd(val); break;
        case 3: cin >> key >> val; d.insertBefore(key, val); break;
        case 4: cin >> key >> val; d.insertAfter(key, val); break;
        case 5: cin >> key; d.deleteNode(key); break;
        case 6: cin >> key; cout << "Position: " << d.search(key) << endl; break;
        case 7: d.display(); break;
        case 8: return 0;
        }
    }
}
