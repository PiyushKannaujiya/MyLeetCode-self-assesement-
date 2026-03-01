#include <bits/stdc++.h>
using namespace std;
void dfs(int i, vector<bool>&vis, vector<vector<int>>&adj, stack<int>&st){
  vis[i]= true;
  for(int a :adj[i]){
    if(!vis[a]){
        dfs(a,vis,adj,st);
    }
  }
  st.push(i);

}




int main(){
    int v =4;
    vector<vector<int>>adj(4);
    vector<bool>vis(v,false);
   adj[0].push_back(1);
    adj[1].push_back(2);
    adj[0].push_back(3);
    adj[3].push_back(2);
stack<int>st;
for(int i =0;i<v;i++){
    if(!vis[i]){
        dfs(i,vis,adj,st);
    }
}
while(!st.empty()){
    int a = st.top();
    st.pop();
    cout  << a<<  " ";
    
}
cout << endl;
    return 0;
}