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
 
node *final(node *root){
     if(root ==  NULL) return NULL;
     
}
node *bst(vector<int>&arr){
    if(arr.size() == 0 ) return NULL;
node *root;
 for(int i =0;i<arr.size();i++){
  root = new node (arr[i]);
 }

final(root);

}



int main(){
      vector<int>arr = {8,5,1,7,10,12}; 
    int y =-1;
    node *root = bst(arr);



    return 0;
}