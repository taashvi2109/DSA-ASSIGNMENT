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

bool isBSTUtil(Node* root, long long minVal, long long maxVal) {
    if (root == NULL) return true;
    if (root->data <= minVal || root->data >= maxVal) return false;
    return isBSTUtil(root->left, minVal, root->data) &&
           isBSTUtil(root->right, root->data, maxVal);
}

bool isBST(Node* root) {
    return isBSTUtil(root, -10000000000LL, 10000000000LL);
}

int main() {
    cout << "Enter tree data in pre-order, -1 for NULL:\n";
    Node* root = buildTree();
    if (isBST(root)) cout << "Tree is a BST\n";
    else cout << "Tree is not a BST\n";
    return 0;
}
