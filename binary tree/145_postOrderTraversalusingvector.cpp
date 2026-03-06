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
void post(node* root ,vector<int>&q){
    if(root == NULL)return;
    post(root -> left,q);
    post(root->right,q);
    q.push_back(root ->data);   
}
void postOrder(node *root){
vector<int>q;
post(root,q);
for(auto &p: q){
     cout <<  p<< " ";
}

}
int main(){
vector<int> arr = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 9, -1, -1};
int x = -1;
node *root = build(arr,x);
postOrder(root);
    return 0;
}