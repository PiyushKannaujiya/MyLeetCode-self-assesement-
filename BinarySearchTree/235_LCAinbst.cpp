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
node*build(vector<int>&arr , int &y){

    y++;
    if(y>=arr.size() || arr[y] == -1) return NULL;
    node *currnode = new node(arr[y]);
    currnode ->left = build(arr,y);
    currnode ->right = build(arr,y);
    return currnode;
}
//   bool find(node *root, node *a){
//     if(root == NULL) return false;
//      if(root  == a ) return true;
//     return find(root ->left,a) || find(root ->right,a);
//   }

// void parent(node *root){
//     queue<node*> q;
//     q.push(root);
//     mp[root] = NULL;

//     while(!q.empty()){
//         node* curr = q.front();
//         q.pop();

//         if(curr->left){
//             mp[curr->left] = curr;
//             q.push(curr->left);
//         }
//         if(curr->right){
//             mp[curr->right] = curr;
//             q.push(curr->right);
//         }
//     }
// }
node *lca(node *root , node *a,node *b){
    if(root ==  NULL) return NULL;
    if(root == a || root == b) return root;
node *left = lca(root ->left, a,b);
node *right = lca(root ->right,a,b);
if(left && right) return root;
 return left?left :right;
}







int main(){
      vector<int>arr = {10,5,3,-1,-1,7,-1,-1,15,12,-1,-1,18,-1,-1}; 
    int y =-1;
    node *root = build(arr,y);
    node *a = root ->left->left; node *b = root->right->left;
 node * ans = lca(root,a,b);
 cout << ans -> data << endl;

    return 0;
}