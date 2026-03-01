#include <bits/stdc++.h>
using namespace std;
class node{
public:
node *left;
   node *right;
   int val;
    node(int val){
        this->val = val;
        right = left = NULL;
    }

};
node*build(vector<int> &arr){

static int x =-1;
x++;

if(arr[x] == -1){
    return NULL;
}

node *currnode= new node(arr[x]);
currnode ->left = build(arr);
currnode ->right = build(arr);
return currnode;
}
int height(node*root){
    if(root == NULL){
       return 0;

    }
int left = height(root ->left);
int right = height(root ->right);
int a =max( left ,right )+ 1; 

 return a;   
}
int main(){
    vector <int> arr = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    node* root =  build(arr);
   cout << height(root)<< endl;
    return 0;
}