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
if(arr.size() <= x || arr[x] ==-1 )return NULL;
node *curr = new node(arr[x]);
curr ->left = build(arr,x);
curr ->right = build(arr,x);
return curr;
}
bool child(node *root){
if(root == NULL) return true;

if(root ->left == NULL &&  root ->right == NULL) return true;
int  l =0,r =0;
if(root ->left)
 l = root ->left->data;

if(root ->right)
 r = root ->right->data;

if(root ->data == l+r && child(root ->left) && child(root ->right))
 return true;



 return false;



}


int main(){
    vector<int>arr = {12, 9, 4, -1, -1, 5, -1, -1, 3, -1, -1};
    int x =-1;
    node *root = build(arr,x);
    bool a =child(root);
 cout <<a  << endl;
return 0;
}