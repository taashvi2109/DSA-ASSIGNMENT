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

Node* findMin(Node* root) {
    if (root == NULL) return NULL;
    while (root->left != NULL) root = root->left;
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (root == NULL) return root;
    if (key < root->data) root->left = deleteNode(root->left, key);
    else if (key > root->data) root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        } else if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        } else {
            Node* succ = findMin(root->right);
            root->data = succ->data;
            root->right = deleteNode(root->right, succ->data);
        }
    }
    return root;
}

int maxDepth(Node* root) {
    if (root == NULL) return 0;
    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);
    return (lh > rh ? lh : rh) + 1;
}

int minDepth(Node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    if (root->left == NULL) return 1 + minDepth(root->right);
    if (root->right == NULL) return 1 + minDepth(root->left);
    int lh = minDepth(root->left);
    int rh = minDepth(root->right);
    return (lh < rh ? lh : rh) + 1;
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
        cout << "\n1.Insert 2.Delete 3.Inorder 4.Max Depth 5.Min Depth 6.Exit\n";
        cin >> choice;
        if (choice == 6) break;
        if (choice == 1) {
            cin >> val;
            root = insertNode(root, val);
        } else if (choice == 2) {
            cin >> val;
            root = deleteNode(root, val);
        } else if (choice == 3) {
            inorder(root);
            cout << "\n";
        } else if (choice == 4) {
            cout << maxDepth(root) << "\n";
        } else if (choice == 5) {
            cout << minDepth(root) << "\n";
        }
    }
    return 0;
}
