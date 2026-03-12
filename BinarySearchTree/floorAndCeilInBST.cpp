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
    if(y>=arr.size() || arr[y] == NULL) return NULL;
    node *currnode = new node(arr[y]);
    currnode ->left = build(arr,y);
    currnode ->right = build(arr,y);
    return currnode;
}
int floor(node *root,int x, int cf){
 if (root ==    NULL) return cf;
   if(root->data == x)return x;
   if(root ->data > x){
   
    return floor(root ->left,x,cf);
   }
   if(root -> data <=x && root ->data > cf){
    cf= root->data;
    return floor( root ->left,x,cf);
   }
}   

// int ceil(node *root, int x){

// }



int main(){
      vector<int>arr = {8,4,2,-1,-1,6,-1,-1,12,10,-1,-1,14,-1,-1}; 
    int y =-1;
    node *root = build(arr,y);
    int x = 5;
    int cf = INT_MIN;
 int flo = floor(root,x,cf);
 if(flo == INT_MIN){
    flo = -1;
 }
cout << flo<< endl;
    return 0;
}