#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node* createNode(int x) {
    Node* temp = new Node;
    temp->data = x;
    temp->left = temp->right = NULL;
    return temp;
}

Node* insertNode(Node* root, int key) {
    if (root == NULL) return createNode(key);
    if (key < root->data) root->left = insertNode(root->left, key);
    else if (key > root->data) root->right = insertNode(root->right, key);
    return root;
}

Node* recursiveSearch(Node* root, int key) {
    if (root == NULL || root->data == key) return root;
    if (key < root->data) return recursiveSearch(root->left, key);
    else return recursiveSearch(root->right, key);
}

Node* iterativeSearch(Node* root, int key) {
    Node* curr = root;
    while (curr != NULL && curr->data != key) {
        if (key < curr->data) curr = curr->left;
        else curr = curr->right;
    }
    return curr;
}

Node* findMin(Node* root) {
    if (root == NULL) return NULL;
    while (root->left != NULL) root = root->left;
    return root;
}

Node* findMax(Node* root) {
    if (root == NULL) return NULL;
    while (root->right != NULL) root = root->right;
    return root;
}

Node* inorderSuccessor(Node* root, int key) {
    Node* target = root;
    while (target != NULL && target->data != key) {
        if (key < target->data) target = target->left;
        else target = target->right;
    }
    if (target == NULL) return NULL;
    if (target->right != NULL) return findMin(target->right);
    Node* succ = NULL;
    Node* curr = root;
    while (curr != NULL) {
        if (key < curr->data) {
            succ = curr;
            curr = curr->left;
        } else if (key > curr->data) {
            curr = curr->right;
        } else break;
    }
    return succ;
}

Node* inorderPredecessor(Node* root, int key) {
    Node* target = root;
    while (target != NULL && target->data != key) {
        if (key < target->data) target = target->left;
        else target = target->right;
    }
    if (target == NULL) return NULL;
    if (target->left != NULL) return findMax(target->left);
    Node* pred = NULL;
    Node* curr = root;
    while (curr != NULL) {
        if (key > curr->data) {
            pred = curr;
            curr = curr->right;
        } else if (key < curr->data) {
            curr = curr->left;
        } else break;
    }
    return pred;
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;
    int choice, val;
    while (true) {
        cout << "\n1.Insert 2.Recursive Search 3.Iterative Search 4.Min 5.Max 6.Inorder Successor 7.Inorder Predecessor 8.Inorder Traversal 9.Exit\n";
        cin >> choice;
        if (choice == 9) break;
        if (choice == 1) {
            cin >> val;
            root = insertNode(root, val);
        } else if (choice == 2) {
            cin >> val;
            Node* res = recursiveSearch(root, val);
            if (res) cout << "Found\n"; else cout << "Not Found\n";
        } else if (choice == 3) {
            cin >> val;
            Node* res = iterativeSearch(root, val);
            if (res) cout << "Found\n"; else cout << "Not Found\n";
        } else if (choice == 4) {
            Node* mn = findMin(root);
            if (mn) cout << mn->data << "\n"; else cout << "Empty\n";
        } else if (choice == 5) {
            Node* mx = findMax(root);
            if (mx) cout << mx->data << "\n"; else cout << "Empty\n";
        } else if (choice == 6) {
            cin >> val;
            Node* s = inorderSuccessor(root, val);
            if (s) cout << s->data << "\n"; else cout << "No Successor\n";
        } else if (choice == 7) {
            cin >> val;
            Node* p = inorderPredecessor(root, val);
            if (p) cout << p->data << "\n"; else cout << "No Predecessor\n";
        } else if (choice == 8) {
            inorder(root);
            cout << "\n";
        }
    }
    return 0;
}
