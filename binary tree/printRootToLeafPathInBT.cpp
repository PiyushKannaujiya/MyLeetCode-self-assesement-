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

void printrootToLeaf(node*root,vector<int>&path){
if(root == NULL) return;
path.push_back(root ->data);

if(root ->left == NULL && root->right == NULL){
    for(auto &it :path){
        cout <<it <<" ";
    }
    cout << endl;
}
printrootToLeaf(root ->left,path);
printrootToLeaf(root ->right,path);
path.pop_back();

}

int main(){
vector<int>arr = {1,2,4,-1,-1,5,-1,-1,3,-1,-1};
int x = -1;
node *root = build(arr,x);
vector<int>path;
printrootToLeaf(root,path);

    return 0;
}