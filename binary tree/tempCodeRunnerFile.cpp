#include <bits/stdc++.h>
using namespace std;
class node {
    public:
        int data;
        node*left,*right;
        node(int val){
            this->data = val;
            left = right = NULL;
        
    }
};
node *build(vector<int>&arr,int &x){
    x++;
    if(arr.size()<=x || arr[x] ==-1)return NULL;
    node *curr = new node(arr[x]);
    curr ->left = build(arr,x);
    curr->right = build(arr,x);
    return curr;
}

void printrootToLeaf(node*root,vector<int>&path){

path.push_back(root ->data);
if(root == NULL) return;
if(root ->left == NULL && root->right == NULL){
    for(auto &it :path){
        cout <<it <<" ";