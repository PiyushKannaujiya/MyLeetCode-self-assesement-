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
    if(x>arr.size() || arr[x] == -1) return NULL;
    node *currnode = new node(arr[x]);
    currnode ->left = build(arr,x);
    currnode ->right = build(arr,x);
    return currnode;
}
void preorder(node*root){
    if(root == NULL)return;

    cout << root ->data << " ,";
    preorder(root ->left);
        preorder(root ->right);

}
int checkheight(node *root){
    if(root == NULL) return 0;

    int l = checkheight(root ->left);

        if(l == -1 ) return -1;
    
        int r = checkheight(root ->right);
        if(r == -1) return -1;
        if(abs(l-r) >1) return -1;

        return max(l,r) +1;
}

bool isBalanced(node *root){
 return checkheight(root ) != -1;
}

int main (){
    vector <int> arr = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    int index = -1;
node*root = build(arr,index);
//preorder(root);
if(isBalanced(root)){
    cout << "true"<< endl;
}
else cout << "false "<< endl;
    return 0;
}
