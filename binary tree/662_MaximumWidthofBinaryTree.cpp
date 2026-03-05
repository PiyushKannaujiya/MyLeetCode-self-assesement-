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
long long maxWidth(node *root){
if(root == NULL)return 0;
queue<pair<node*,long long>>q;
q.push({root,0});
   long long ans =0;

while(!q.empty())
{
long long start = q.front().second;
long long end = q.back().second;
ans = max(ans,end -start +1);
int size = q.size();
for(int i =0;i<size;i++){
    auto p = q.front();
    q.pop();
    node * curr = p.first;
    long long idx = p.second - start;
    if(curr ->left)q.push({curr->left,2*idx+1});
    if(curr->right)q.push({curr->right,2*idx+2});
}
}
return ans;


}



int main (){
vector<int> arr = {1,3,5,-1,-1,3,-1,-1,2,-1,9,-1,-1};
    int x = -1;
node *root = build(arr,x);
cout << maxWidth(root) << endl;
    return 0;
}