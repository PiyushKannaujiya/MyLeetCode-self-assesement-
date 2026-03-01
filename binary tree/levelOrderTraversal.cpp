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

node *build(vector<int> &arr){
    static int x = -1;
    x++;
    if(arr[x]  == -1){
        return NULL;
    }
     node * currnode = new node(arr[x]);
     currnode ->left = build(arr);
     currnode ->right = build(arr);
     return currnode;
}
void levelTraversal(node *root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node *curr = q.front();
           q.pop();

  if(curr == NULL){
    cout << endl;
  if(q.empty()) break;
  q.push(NULL);
   continue;
  }

 

     cout << curr->val << " ";

        if(curr->left !=   NULL){
            q.push(curr->left);
        }
  if(curr->right !=   NULL){
            q.push(curr->right);
        }
    }
    }

int main(){
    vector <int> arr = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    node *root = build(arr);
    levelTraversal(root);
    return 0;
}