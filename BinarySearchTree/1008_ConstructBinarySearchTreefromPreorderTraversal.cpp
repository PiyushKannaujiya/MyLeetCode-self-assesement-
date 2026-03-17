#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node *left;
    node *right;

    node(int val){
        data = val;
        left = right = NULL;
    }
};

//////////////////// BUILD BST FROM PREORDER ////////////////////
node* build(vector<int>& pre, int &i, long long minv, long long maxv){
    if(i >= pre.size()) return NULL;

    // if current value not in range → cannot be placed here
    if(pre[i] <= minv || pre[i] >= maxv)
        return NULL;

    node* root = new node(pre[i]);
    i++;

    root->left = build(pre, i, minv, root->data);
    root->right = build(pre, i, root->data, maxv);

    return root;
}

node* bstFromPreorder(vector<int>& pre){
    int i = 0;
    return build(pre, i, LLONG_MIN, LLONG_MAX);
}

//////////////////// INORDER (CHECK) ////////////////////
void inorder(node* root){
    if(root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

//////////////////// MAIN ////////////////////
int main(){
    vector<int> pre = {8,5,1,7,10,12};

    node* root = bstFromPreorder(pre);

    cout << "Inorder: ";
    inorder(root);   // should be sorted
    cout << endl;

    return 0;
}