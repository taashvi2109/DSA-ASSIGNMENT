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

    int countAndDelete(int key) {
        int count = 0;

        // delete from beginning
        while (head && head->data == key) {
            count++;
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        // delete from middle/end
        Node* curr = head;
        while (curr && curr->next) {
            if (curr->next->data == key) {
                count++;
                Node* del = curr->next;
                curr->next = curr->next->next;
                delete del;
            } else {
                curr = curr->next;
            }
        }

        return count;
    }

    void display() {
        Node* t = head;
        while (t) { cout << t->data << " "; t = t->next; }
        cout << endl;
    }
};

int main() {
    LinkedList l;
    l.insertEnd(1);
    l.insertEnd(2);
    l.insertEnd(1);
    l.insertEnd(2);
    l.insertEnd(1);
    l.insertEnd(3);
    l.insertEnd(1);

    int key = 1;

    int cnt = l.countAndDelete(key);
    cout << "Count: " << cnt << endl;

    cout << "Updated List: ";
    l.display();
}
