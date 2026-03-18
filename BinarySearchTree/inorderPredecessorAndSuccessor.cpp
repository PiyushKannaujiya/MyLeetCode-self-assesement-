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
node*build(vector<int>&arr , int &y){

    y++;
    if(y>=arr.size() || arr[y] == -1) return NULL;
    node *currnode = new node(arr[y]);
    currnode ->left = build(arr,y);
    currnode ->right = build(arr,y);
    return currnode;
}
int predecessor(node *root, int key){
    node* pre = NULL;

    while(root != NULL){

        if(root->data < key){
            pre = root;                 
            root = root->right;
        }
        else if(root->data > key){
            root = root->left;
        }
        else{
     
            if(root->left){
                node *curr = root->left;
                while(curr->right != NULL){
                    curr = curr->right;
                }
                pre = curr;
            }
            break;
        }
    }

    if(pre) return pre->data;
    return -1;
}

int successor(node *root, int key){
    if(root == NULL) return -1;

    node *suc = NULL;

    while(root != NULL){

        if(root->data > key){
            suc = root;
            root = root->left;
        }
        else if(root->data < key){
            root = root->right;
        }
        else{

            if(root->right){
                node *curr = root->right;

                while(curr->left != NULL){
                    curr = curr->left;
                }

                suc = curr;
            }
            break;
        }
    }

    if(suc) return suc->data;
    return -1;
}




int main(){
      vector<int>arr = {10,5,3,-1,-1,7,-1,-1,15,12,-1,-1,18,-1,-1}; 
    int y =-1;
    node *root = build(arr,y);
int key =3;
 int a = predecessor(root,key);
 cout << a << endl;
  int b = successor(root,key);
 cout << b << endl;
    return 0;
}