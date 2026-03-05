#include <bits/stdc++.h>
using namespace std;
class node {
    public:
    int data;
    node *left, *right;
    node(int val){
        this->data = val;
        left = right =  NULL;
    }
};
node *build(vector<int>&arr,int &x){
    x++;
    if(x >= arr.size() || arr[x] == -1)return NULL;
    node *curr = new node(arr[x]);
    curr ->left = build(arr,x);
    curr ->right = build(arr,x);
    return curr;
}
int maxWidth(node *root){
if(root == NULL)return 0;
queue<pair<node*,long long>>q;
q.push({root,1});
int ans =0;
while(!q.empty()){
int a = q.size();
q.pop();
ans = max(ans,a);
q.push()



}

}

int main (){
    vector<int> arr = {1,2,3,4};
    int x = -1;
node *root = build(arr,x);
    return 0;
}