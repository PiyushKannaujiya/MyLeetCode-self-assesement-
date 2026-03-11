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
    if(x>=arr.size() || arr[x] == NULL) return NULL;
    node *currnode = new node(arr[x]);
    currnode ->left = build(arr,x);
    currnode ->right = build(arr,x);
    return currnode;
}
int floor(node *root,int x){
 if (root ==    NULL) return -1;
  
}    



int main(){
      vector<int>arr = {8,4,2,-1,-1,6,-1,-1,12,10,-1,-1,14,-1,-1}; 
    int x =-1;
    node *root = build(arr,x);
    int flot = 5;
 int flo = floor(root,flot);

    return 0;
}