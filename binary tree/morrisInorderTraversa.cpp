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
void morrisInorder(node *root){
 node *curr = root;
 while(curr != NULL){

    // if left not exit;
    if(curr ->left == NULL){
         cout << curr ->data << " ";
         curr = curr ->right;
    }

    // if left exit

    else {
        node *pred = curr ->left;
        while(pred ->right != NULL && pred->right != curr){
             pred = pred ->right;
        }

        // thread not created
        if(pred ->right != curr){
            pred ->right = curr;
            curr = curr ->left;
        }

        // already thread exit
        else {
            pred ->right = NULL;
            cout << curr ->data << " ";
            curr = curr ->right;
        }
    }
 }

}

node*build(vector<int>&arr , int &x){

    x++;
    if(x>=arr.size() || arr[x] == -1) return NULL;
    node *currnode = new node(arr[x]);
    currnode ->left = build(arr,x);
    currnode ->right = build(arr,x);
    return currnode;
}



int main(){
      vector<int>arr = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 9, -1, -1};
    int x =-1;
    node *root = build(arr,x);
morrisInorder(root);
    return 0;
}