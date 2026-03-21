#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node *left;
    node *right;

    node(int val) {
        data = val;
        left = right = NULL;
    }
};

node* build(vector<int>& arr, int &i) {
    i++;
    if (i >= arr.size() || arr[i] == -1) return NULL;

    node* root = new node(arr[i]);
    root->left = build(arr, i);
    root->right = build(arr, i);

    return root;
}

node *first = NULL, *second = NULL, *prevNode = NULL;

void inorder(node* root) {
    if (!root) return;

    inorder(root->left);

    if (prevNode && root->data < prevNode->data) {
        if (!first) first = prevNode;
        second = root;
    }

    prevNode = root;

    inorder(root->right);
}

node* recover(node* root) {
    inorder(root);

    if (first && second)
        swap(first->data, second->data);

    return root;
}

void print(node* root) {
    if (!root) return;
    print(root->left);
    cout << root->data << " ";
    print(root->right);
}

int main() {
    vector<int> arr = {1, 3, -1, 2, -1, -1, -1};
    int i = -1;

    node* root = build(arr, i);

    cout << "Before recover: ";
    print(root);
    cout << endl;

    recover(root);

    cout << "After recover: ";
    print(root);
    cout << endl;

    return 0;
}