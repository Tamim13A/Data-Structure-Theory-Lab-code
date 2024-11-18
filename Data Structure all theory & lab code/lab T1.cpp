#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = node->right = nullptr;
    return node;

}

// Improved insert function with error handling
Node* insert(Node* root, int data) {
    if (root == nullptr) {
        return newNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right,  
 data);  

    } else {
        // Handle duplicate values (e.g., ignore or update existing node)
        cout << "Duplicate value: " << data << " ignored.\n";
    }

    return root;
}

// In-order traversal function
void inorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main() {
    Node* root = nullptr; 

    int n, data;

    cout << "Enter the number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value to insert: ";
        cin >> data;
        root = insert(root, data);
    }

    cout << "In-order traversal of the BST: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}