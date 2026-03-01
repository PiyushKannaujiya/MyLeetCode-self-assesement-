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
void traversal(node *root,vector<vector<int>>&ans){
   
    if(root ==  NULL){
        return ;
    }
    queue <node*>q;
   
    q.push(root);
while(!q.empty()){
int size = q.size();
 vector<int>level;
for (int  i = 0; i<size; i++){
    node *curr = q.front();
    q.pop();
 
  level.push_back(curr ->val);
  if(curr ->left != NULL) q.push(curr ->left);
 if(curr ->right != NULL) q.push(curr ->right);

}
 ans.push_back(level);
}


 


}

int main(){
    vector <int> arr = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    node* root =  build(arr);
    vector <vector <int>> ans;
 traversal(root, ans);
   for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
       
    }
    return 0;
}