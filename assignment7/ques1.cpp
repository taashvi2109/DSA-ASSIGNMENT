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

Node* buildTree() {
    int x;
    cin >> x;
    if (x == -1) return NULL;
    Node* root = createNode(x);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

void preorder(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    cout << "Enter tree data in pre-order form, use -1 for NULL:\n";
    Node* root = buildTree();

    cout << "Preorder: ";
    preorder(root);
    cout << "\nInorder: ";
    inorder(root);
    cout << "\nPostorder: ";
    postorder(root);
    cout << "\n";
    return 0;
}
