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
string searlize(node *root){

}


int main(){
      vector<int>arr = {1, 2, 4, NULL, NULL, 5,NULL, NULL, 3, NULL, 9, NULL, NULL};
    int x =-1;
    node *root = build(arr,x);

    return 0;
}