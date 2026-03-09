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
vector<int>ans;
// void rightView(node *root){
//     if(root == NULL) return ;
// queue<node*>q;
// q.push(root);

//  while (!q.empty())
//  {
//         int n = q.size();

// for(int i =0;i<n;i++){
//    node * curr = q.front();
//    q.pop();
//     if(i == n-1){
//         ans.push_back(curr ->data);
//     }
//     if(curr ->left) q.push(curr ->left);
//         if(curr ->right) q.push(curr ->right);

// }

// }
// }


void recursionRightview(node *root,vector<int>&ans,int level){
   if(root == NULL) return ;
if(ans.size() == level){
    ans.push_back(root ->data);
}
recursionRightview(root ->right,ans,level+1);
recursionRightview(root ->right,ans,level+1);

}
void print(vector<int>&ans){
    for(int i =0;i<ans.size();i++){
        cout << ans[i] << " ";
        cout << endl;
    }
}

int main(){
      vector<int>arr = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 9, -1, -1};
    int x =-1;
    node *root = build(arr,x);
   // rightView(root);
   recursionRightview(root,ans,0);
print(ans);
    return 0;
}