#include <bits/stdc++.h>
using namespace std;
int findparent(int node,vector<int>&parent){
    if(parent[node] != node) 
    parent[node] = findparent(parent[node],parent);
    return parent[node];
}
void dsu(int x, int y,vector<int>&parent,vector<int>&rank){
    int px = findparent(x, parent);
    int py = findparent(y,parent);
    if(px == py) return;
 if(rank[px]<rank[py]){
    parent[px] = py;
 }
 else if(rank[px]>rank[py]){
    parent[py] = px;
 }else {
 parent[py] = px;
 rank[px]++;
 }
}
int movestone(vector<vector<int>> &graph){
int n = graph.size();
vector<int> parent(n),rank(n,0);

for(int i =0;i<n;i++){
    parent[i]= i;
}
for(int i =0;i<n;i++){
    for(int j = i+1;j<n;j++){
        if(graph[i][0] == graph[j][0] || graph[i][1] == graph[j][1]){
            dsu(i,j,parent,rank);
        }
    }
}

int component = 0;
for(int i =0;i<n;i++){
    if(findparent(i,parent) == i){
        component++;
    }

 }
  return n-component;



}





int main (){
vector<vector<int>>graph = {
    {0,0},{0,1},{1,0},{2,1},{2,2}
};
int a = movestone(graph);
cout << a<< endl;
    return 0;
}