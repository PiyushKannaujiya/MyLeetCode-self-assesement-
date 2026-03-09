#include <bits/stdc++.h>
using namespace std;
class node {
    public:
    int data;
    node *left;
    node *right;
    node(int val){
        this ->data = val;
        left = right =  NULL;
    }
};
node*build(vector<int>&arr , int &x){

    x++;
    if(x>=arr.size() || arr[x] == -1) return NULL;
    node *currnode = new node(arr[x]);
    currnode ->left = build(arr,x);
    currnode ->right = build(arr,x);
    return currnode;
}
bool solve(node *a , node*b){
 if(a == NULL && b== NULL) return true;
 if( a == NULL || b == NULL ) return false;
 if( a->data != b->data) return false;
 return solve(a->left ,b->right) && solve(a ->right ,b->left);
}
bool symmetric(node *root){
if(root == NULL) return true;
return solve(root ->left, root->right);
}

int main(){
    vector<int>arr = {1, 2, 3,-1,-1,4,-1,-1,2,3,-1,-1,4,-1,-1};
    int x =-1;
    node *root = build(arr,x);
bool a = symmetric(root);
 cout << a<< endl;
    return 0;
}