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

node *insert(node *root, int i){
 if(root == NULL){
   return new node(i);
 
 }
  if(root ->data > i){
    root ->left = insert(root ->left ,i);
  }
  else 
  root ->right = insert(root ->right ,i);

  return root;
}

node*build(vector<int>&arr ){
    node *root =   NULL;

for(int i =0;i<arr.size();i++){
   root = insert(root ,arr[i]);
}
return root;
}
void print(node *root){
    if(root == NULL) return ;
 cout << root ->data << " ";
 print(root ->left);
 print(root ->right);

}




int main(){
      vector<int>arr = {8,15,1,7,-1,122}; 
 node *root = build(arr);
print(root);


    return 0;
}