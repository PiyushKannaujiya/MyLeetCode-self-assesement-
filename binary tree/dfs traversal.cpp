#include <bits/stdc++.h>
using namespace std;
class node{
public:
node *left;
   node *right;
   int val;
    node(int val){
        this->val = val;
        right = left = NULL;
    }

};
node *build(vector<int> &arr){
    static int x= -1;
    x++;
    if(arr[x]== -1){
        return NULL;
    }
    node *currnode = new node(arr[x]);
    currnode ->left = build(arr);
    currnode ->right = build(arr);
    return currnode;
   
}
void preorder(node*root){
    if(root == NULL){
        return;
    }
    cout << root->val << " ";
    preorder(root ->left);
    preorder(root->right);

}

int main(){
    vector <int> arr = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    node* root =  build(arr);
    preorder(root);
    return 0;
}