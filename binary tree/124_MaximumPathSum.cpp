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
int maximum(node*root){
    if(root == NULL)return 0;
int ans = INT_MIN;
int l = max(0,maximum(root ->left));
int r =max(0, maximum(root ->right));
 ans = max(ans,root->data +l+r);
return root ->data +max(l,r);

}

int main(){
    vector<int>arr ={1,2,4,-1,-1,5,-1,-1,3,-1,-1};
    int x= -1;
node *root = build(arr,x);
int a = maximum(root);
cout <<a << endl;
    return 0;
}