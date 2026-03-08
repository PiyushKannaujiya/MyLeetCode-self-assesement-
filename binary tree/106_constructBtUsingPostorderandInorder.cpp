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

 node *solve(vector<int>postorder,vector<int>inorder,int start, int end, int &preidx){
    if(start >end) return NULL;

    int rootval = postorder[preidx--];
    node * treenode = new node(rootval);
    int pos = start;
    while(inorder[pos] != rootval){
        pos++;
    }
       treenode->right =   solve(postorder,inorder,pos +1,end,preidx);

   treenode->left= solve(postorder,inorder,start,pos -1,preidx);

return treenode;
 }
node * construct(vector<int>postorder,vector<int>inorder){
int preidx =postorder.size() -1;;
return solve(postorder,inorder,0,inorder.size()-1,preidx);

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
    vector<int>postorder= {9,15,7,20,3};
    vector<int>inorder = {9,3,15,20,7};

node *root =construct(postorder,inorder);
print(root);
    return 0;
}