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
vector<vector<int>>res;
vector<vector<int>> vertical(node *root){
    if(root == NULL)return {{}};
   map<int,map<int,vector<int>>>mp;
   



}



int main(){
    vector<int>arr = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 9, -1, -1};
    int x =-1;
    node *root = build(arr,x);
 vertical(root);
return 0;
}