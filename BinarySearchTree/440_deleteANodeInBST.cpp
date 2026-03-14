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
int findmin(node *root){
    node *curr = root ->right;
    while(curr ->left != NULL){
        curr = curr ->left;
        if(curr ->left == NULL){
            if(curr ->right) return curr ->right ->data;
        }
    }
    return curr ->data;
}
void del(node *root ){
    if(root ==NULL)return ;

}



int main(){
      vector<int>arr = {8,4,2,-1,-1,6,-1,-1,12,10,5,-1,-1,14,-1,-1}; 
    int y =-1;
    node *root = build(arr,y);
 del(root);


    return 0;
}