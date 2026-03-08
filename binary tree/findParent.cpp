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
node*build(vector<int>&arr , int &x){

    x++;
    if(x>=arr.size() || arr[x] == -1) return NULL;
    node *currnode = new node(arr[x]);
    currnode ->left = build(arr,x);
    currnode ->right = build(arr,x);
    return currnode;
}

void findParent(node * root ){
    if(root == NULL) return ;
unordered_map< node *,node*>m;
queue<node*>q;
q.push(root);
    m[root] =  NULL;
while(!q.empty()){
    node *curr = q.front();
    q.pop();

    if(curr ->left){
        m[curr ->left] = curr;
        q.push(curr->left);
    }

     if(curr ->right){
        m[curr ->right] = curr;
        q.push(curr->right);
    }

}
for(auto &p :m){
  node * child = p.first;
  node *parent = p.second;
  cout << child ->data << "->";
  if(parent == NULL) cout << "null" << endl;
  else  cout << parent ->data << endl;
    
}



}




int main(){
    vector<int>arr = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 9, -1, -1};
    int x =-1;
    node *root = build(arr,x);
findParent(root);
    return 0;
}