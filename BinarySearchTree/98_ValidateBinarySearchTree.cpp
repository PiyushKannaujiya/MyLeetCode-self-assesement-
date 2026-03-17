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

bool solve(node *root,long long minv, long long maxv){
    if(root ==      NULL ) return true;

if(root ->data <= minv || root ->data >= maxv) return false;

return solve(root->left ,minv, root ->data ) && solve(root ->right, root->data,maxv);
}
bool validate(node *root){
   if(root ==  NULL)  return true;
   return solve(root,LLONG_MIN, LLONG_MAX);
}



int main(){
vector<int> arr = {2,1,-1,-1,3,-1,-1};    int y =-1;
    node *root = build(arr,y);

cout << validate(root ) << endl;

    return 0;
}