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

 node *solve(vector<int>preorder,vector<int>inorder,int start, int end, int &preidx){
    if(start >end) return NULL;

    int rootval = preorder[preidx++];
    node * treenode = new node(rootval);
    int pos = start;
    while(inorder[pos] != rootval){
        pos++;
    }
   treenode->left= solve(preorder,inorder,start,pos -1,preidx);
   treenode->right =   solve(preorder,inorder,pos +1,end,preidx);

return treenode;
 }
node * construct(vector<int>preorder,vector<int>inorder){
int preidx =0;
return solve(preorder,inorder,0,inorder.size()-1,preidx);

}
void print(node* root)
{
    if(root == NULL)
    {
        cout << -1 << " ";
        return;
    }

    cout << root->data << " ";

    print(root->left);
    print(root->right);
}

int main (){
    vector<int>preorder= {3,9,20,15,7};
    vector<int>inorder = {9,3,15,20,7};

node *root =construct(preorder,inorder);
print(root);
    return 0;
}