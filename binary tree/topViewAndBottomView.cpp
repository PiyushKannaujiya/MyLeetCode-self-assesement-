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
vector<int>topv;
vector<int>botv;
node*build(vector<int>&arr , int &x){

    x++;
    if(x>=arr.size() || arr[x] == -1) return NULL;
    node *currnode = new node(arr[x]);
    currnode ->left = build(arr,x);
    currnode ->right = build(arr,x);
    return currnode;
}
void topview(node *root,    map<int,node*>&mp,int idx
){
    if(root ==  NULL) return;
    queue<pair<int,node*>>q;
    q.push({0,root});
    while(!q.empty()){
         auto  p = q.front();
         int idx = p.first;
         node *curr = p.second;
         q.pop();
 if(mp.find(idx) ==  mp.end()){
    mp[idx] = curr;
 }
 if(curr ->left) q.push({idx -1,curr ->left});
  if(curr ->right) q.push({idx +1,curr ->right}) ;

    }
     for(auto &it : mp){
         topv.push_back(it.second ->data);
    }
}
void bottomview(node *root,    map<int,node*>&mp,int idx
){
    if(root ==  NULL) return;
    queue<pair<int,node*>>q;
    q.push({0,root});
    while(!q.empty()){
         auto  p = q.front();
         int idx = p.first;
         node *curr = p.second;
         q.pop();

    mp[idx] = curr;
   
 
 if(curr ->left) q.push({idx -1,curr ->left});
  if(curr ->right) q.push({idx +1,curr ->right}) ;

    }
    for(auto &it : mp){
         botv.push_back(it.second ->data);
    }
}
void print(vector<int>&ans){
    for(int i =0;i<ans.size();i++){
        cout << ans[i] << " ";
        
    }
    cout << endl;
}


int main(){
      vector<int>arr = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 9, -1, -1};
    int x =-1;
    node *root = build(arr,x);
    map<int,node*>mp;

   topview(root,mp,0);
      bottomview(root,mp,0);

print(topv);
print(botv);

    return 0;
}