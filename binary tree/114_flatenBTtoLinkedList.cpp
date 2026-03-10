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
    node *temp = NULL;

void  flatten(node *root){
    if(root == NULL) return;
    flatten(root ->right);
    flatten(root ->left);
    root ->right = temp;
    root ->left = NULL;
    temp = root;

}

void print( node * root){
  if(root == NULL) return;
  cout << root ->data <<" ";
  if(root ->left) print(root ->left);
    if(root ->right) print(root ->right);

}

int main(){
    vector<int>arr = {1, 2, 3,-1,-1,4,-1,-1,5,-1,6,-1,-1};
    int x =-1;
    node *root = build(arr,x);
 flatten(root);
 print(root);
    return 0;
}
