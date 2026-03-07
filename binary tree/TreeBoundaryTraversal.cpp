#include <bits/stdc++.h>
using namespace std;


class node {
    public:
    int data;
    node *left, *right;
    node(int val){
        this->data = val;
        left = right =  NULL;
    }
};


node *build(vector<int>&arr,int &x){
    x++;
    if(x >= arr.size() || arr[x] == -1)return NULL;
    node *curr = new node(arr[x]);
    curr ->left = build(arr,x);
    curr ->right = build(arr,x);
    return curr;
}
void leftside(node* root, vector<int>& res){
    if(root == NULL)return ;

    node* curr = root;

    while(curr){
if(!(curr ->left == NULL && curr ->right == NULL)){
      //  cout << curr->data << " ";
        res.push_back(curr->data);
}
        if(curr->left)
            curr = curr->left;
        else
            curr = curr->right;
    }
}
void leaf(node*root,vector <int>&res){
    if(root == NULL)return ;
 node *curr = root;
 if(curr ->left == NULL && curr ->right == NULL){
  //  cout << curr ->data<< " ";
        res.push_back(curr->data);

 }
 if(curr ->left)leaf(curr ->left,res);
 if (curr ->right)leaf(curr ->right,res);

}
void rightside(node*root,vector <int>&res){
    if(root == NULL)return ;
 node *curr = root  ->right;
 vector <int>temp;
 while(curr ){
    if(!(curr ->left == NULL && curr ->right == NULL)){

     temp.push_back(curr ->data);
    }
  if(  curr ->right){
    curr = curr ->right;
  }
  else 
  curr = curr ->left;
 }
reverse(temp.begin(),temp.end());
for(auto &x : temp){

     res.push_back(x);
}
} 


 void print(    vector<int>res){
  for(auto &x : res){

     cout << x<< " ";  
}
 }






int main(){
    vector<int>arr = {1, 2, 4, -1, -1, 5, -1, -1, 3, 7, 9, -1, -1};
    int x =-1;
    node *root = build(arr,x);
    vector<int>res;
 leftside(root,res);
 leaf(root,res);
  rightside(root,res);
  print(res);
    return 0;
}