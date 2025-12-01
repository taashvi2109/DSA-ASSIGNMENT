#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    // (a) INSERT AT BEGINNING
    void insertBeg(int val) {
        Node* newnode = new Node(val);
        newnode->next = head;
        head = newnode;
    }

    // (b) INSERT AT END
    void insertEnd(int val) {
        Node* newnode = new Node(val);

        if (head == NULL) {
            head = newnode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newnode;
    }

    // (c) INSERT BEFORE A VALUE
    void insertBefore(int key, int val) {
        Node* newnode = new Node(val);

        if (head == NULL) return;

        if (head->data == key) {
            newnode->next = head;
            head = newnode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL && temp->next->data != key)
            temp = temp->next;

        if (temp->next == NULL) return;

        newnode->next = temp->next;
        temp->next = newnode;
    }

    // (c) INSERT AFTER A VALUE
    void insertAfter(int key, int val) {
        Node* temp = head;

        while (temp != NULL && temp->data != key)
            temp = temp->next;

        if (temp == NULL) return;

        Node* newnode = new Node(val);
        newnode->next = temp->next;
        temp->next = newnode;
    }

    // (d) DELETE FROM BEGINNING
    void deleteBeg() {
        if (head == NULL) return;

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // (e) DELETE FROM END
    void deleteEnd() {
        if (head == NULL) return;

        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }

        Node* temp = head;
        while (temp->next->next != NULL)
            temp = temp->next;

        delete temp->next;
        temp->next = NULL;
    }

    // (f) DELETE SPECIFIC NODE
    void deleteSpecific(int key) {
        if (head == NULL) return;

        if (head->data == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL && temp->next->data != key)
            temp = temp->next;

        if (temp->next == NULL) return;

        Node* del = temp->next;
        temp->next = temp->next->next;
        delete del;
    }

    // (g) SEARCH FOR A VALUE
    int search(int key) {
        Node* temp = head;
        int pos = 1;

        while (temp != NULL) {
            if (temp->data == key) return pos;
            temp = temp->next;
            pos++;
        }
        return -1;
    }

    // (h) DISPLAY LIST
    void display() {
        Node* temp = head;

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// 🟩 MENU-DRIVEN MAIN
int main() {
    LinkedList list;
    int choice, val, key;

    while (true) {
        cout << "\nMENU\n";
        cout << "1. Insert at Beginning\n2. Insert at End\n3. Insert Before\n4. Insert After\n";
        cout << "5. Delete from Beginning\n6. Delete from End\n7. Delete Specific\n";
        cout << "8. Search Value\n9. Display List\n10. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cin >> val;
            list.insertBeg(val);
            break;
        case 2:
            cin >> val;
            list.insertEnd(val);
            break;
        case 3:
            cin >> key >> val;
            list.insertBefore(key, val);
            break;
        case 4:
            cin >> key >> val;
            list.insertAfter(key, val);
            break;
        case 5:
            list.deleteBeg();
            break;
        case 6:
            list.deleteEnd();
            break;
        case 7:
            cin >> key;
            list.deleteSpecific(key);
            break;
        case 8:
            cin >> key;
            cout << "Position: " << list.search(key) << endl;
            break;
        case 9:
            list.display();
            break;
        case 10:
            return 0;
        }
    }
}
