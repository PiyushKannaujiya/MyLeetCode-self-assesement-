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
int floor(node *root,int x, int cf){
 if(root == NULL )return cf;
 if(root ->data == x) return x;
 if(root ->data >x){
    return floor(root ->left,x, cf);
 }
  if(root ->data < x){
     cf = root ->data;
     return floor(root ->right,x,cf);
  }
return cf;
}   

 int ceil(node *root, int x,int cff){
 if(root == NULL )return cff;
 if(root ->data == x) return x;
 if(root ->data >x){
     cff = root ->data;
    return ceil(root ->left,x, cff);
 }
  if(root ->data < x){
    
     return ceil(root ->right,x,cff);
  }
return cff;
 }



/// main funtion



int main(){
      vector<int>arr = {8,4,2,-1,-1,6,-1,-1,12,10,-1,-1,14,-1,-1}; 
    int y =-1;
    node *root = build(arr,y);



    return 0;
}