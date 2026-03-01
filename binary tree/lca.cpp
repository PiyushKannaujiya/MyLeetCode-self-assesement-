#include <bits/stdc++.h>
using namespace std;
class node {
public:
int data;
node*left;
node*right;

node(int data){
    this->data = data;
    left = right = NULL;
}
};

bool nodeToroot(node*root, int n, vector<int>&path){
    if(root == NULL){
        return false;
    }
    path.push_back(root ->data);
    if(root ->data == n){
        return true;
    }

  if(nodeToroot(root ->left,n,path) ||nodeToroot(root ->right,n,path)){
    return true;
  }
  path.pop_back();
  return false;
}

int lca(node*root, int a, int b){
    if(root == NULL){
        return 0;
    }
   
    vector <int>path1;
    vector<int> path2;
    nodeToroot(root,a,path1);
        nodeToroot(root,b,path2);
      int  lca = -1;
     int m = min(path1.size(),path2.size());
 for( int i =0; i<m; i++) {
    if(path1[i] != path2[i]){
        return lca;
    }
    lca = path1[i];
 }      
return lca;
    
}

node *build(vector<int>&arr){
    static int x =-1;
    x++;
    if(arr[x] ==-1){
        return NULL;
    }
    node *curr = new node(arr[x]);
    curr -> left = build(arr);
    curr -> right = build(arr);
    return curr;
}

int main(){
    vector <int> arr = {  3,
  5,
  6, -1, -1,
  2,
    7, -1, -1,
    4, -1, -1,
  1,
  0, -1, -1,
  8, -1, -1
};
    node *root = build(arr);
    int a = 5,b = 1;
   cout << lca(root,a,b) << endl;
    return 0;
}