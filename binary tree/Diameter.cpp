#include <bits/stdc++.h>
using namespace std;
class node {
    public :
  int data;
  node *left;
  node *right;
  node( int data ){
    this ->data = data;
    left = right = NULL;
  }
};

node * build(vector<int>&arr){
    static int x = -1;
    x++;
    if(arr[x] == -1){
        return NULL;
    }
    node *curr = new node(arr[x]);
    curr -> left = build(arr);
    curr ->right = build (arr);
    return curr;
}
int dia =0;
int height(node *root){
    if(root == NULL){
        return 0;
    }
    int left = height(root ->left);
    int right = height(root ->right);
    dia = max(dia, left +right);
    return max(left, right)+1;
}
int diameter(node *root){
    if(root == NULL){
        return 0;;
    }
    height(root);
    return dia;
}


int main (){
 vector <int> arr = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    node* root =  build(arr);
    cout <<diameter(root)<< endl;
    return 0;
}