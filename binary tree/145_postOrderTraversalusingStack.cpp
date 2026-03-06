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

void postOrder(node*root){
if(root == NULL)return;
stack <node *>st;
st.push(root);
   vector<int>v;
while(!st.empty()){
   node *curr = st.top();
   st.pop();
   if(curr ->right) st.push(curr ->right);
   if(curr ->left) st.push(curr ->left);
   




v.push_back(curr->data);

}
for(int i =v.size()-1;i>=0;i--){
    cout << v[i]<< " ";
}

}
int main (){
    vector<int>arr = {1,2,4,-1,-1,5,-1,-1,3,-1,-1};
    int x =-1;
node *root = build(arr,x);
postOrder(root);
    return 0;
}