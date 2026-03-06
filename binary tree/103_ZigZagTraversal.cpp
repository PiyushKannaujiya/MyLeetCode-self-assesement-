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
vector<vector<int>>ans;

vector<vector<int>>zigzag(node *root){
    if(root == NULL)return {};
queue<node *>q;
q.push(root);

int level =0;
while (!q.empty()){
 int n = q.size();
vector<int>res;

 for(int i =0;i<n;i++){
     node *curr = q.front();
   q.pop(); 
   res.push_back(curr ->data);
   if(curr ->left) q.push(curr ->left);
   if(curr ->right) q.push(curr ->right);
}
if(level %2 != 0 )
{
    reverse(res.begin(),res.end());
}
ans.push_back(res);
level++;
}
return ans;
}




int main(){
    vector<int>arr = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 9, -1, -1};
    int x =-1;
    node *root = build(arr,x);
zigzag(root);
for(auto &p :ans){
    for(auto &c :p){
        cout << c << " ";
    }
    cout << endl;
}
    return 0;
}