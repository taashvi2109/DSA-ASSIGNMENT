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

    // Insert anywhere
    void insertEnd(int val) {
        Node* n = new Node(val);

        if (!head) {
            head = n;
            n->next = head;
            return;
        }

        Node* t = head;
        while (t->next != head)
            t = t->next;

        t->next = n;
        n->next = head;
    }

    void insertBeg(int val) {
        Node* n = new Node(val);

        if (!head) {
            head = n;
            n->next = head;
            return;
        }

        Node* t = head;
        while (t->next != head) t = t->next;

        n->next = head;
        t->next = n;
        head = n;
    }

    void insertAfter(int key, int val) {
        if (!head) return;

        Node* t = head;
        do {
            if (t->data == key) {
                Node* n = new Node(val);
                n->next = t->next;
                t->next = n;
                return;
            }
            t = t->next;
        } while (t != head);
    }

    void insertBefore(int key, int val) {
        if (!head) return;

        if (head->data == key) { insertBeg(val); return; }

        Node* t = head;
        Node* prev = NULL;

        do {
            if (t->data == key) {
                Node* n = new Node(val);
                prev->next = n;
                n->next = t;
                return;
            }
            prev = t;
            t = t->next;

        } while (t != head);
    }

    void deleteNode(int key) {
        if (!head) return;

        Node* t = head;
        Node* prev = NULL;

        // deleting head
        if (head->data == key) {
            while (t->next != head) t = t->next;
            t->next = head->next;
            Node* del = head;
            head = head->next;
            delete del;
            return;
        }

        // other nodes
        t = head;
        do {
            if (t->data == key) {
                prev->next = t->next;
                delete t;
                return;
            }
            prev = t;
            t = t->next;

        } while (t != head);
    }

    int search(int key) {
        if (!head) return -1;
        Node* t = head;
        int pos = 1;

        do {
            if (t->data == key) return pos;
            pos++;
            t = t->next;
        } while (t != head);
