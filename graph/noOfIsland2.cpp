#include <bits/stdc++.h>
using namespace std;
int findparent(int node,vector<int>&parent){
    if(parent[node ] != node )
        parent[node ] = findparent(parent[node],parent);
    return parent[node];

}


void dsu(int x,int y,vector<int>&parent, vector<int>&rank,int &count){
  
 int px = findparent(x,parent);
 int py = findparent(y,parent);
   if(px == py) return;

 if(rank[px] > rank[py]){
    parent[py] = px;
 }
 else if(rank[px] < rank[py]){
    parent[px] = py;
 }
 else 
{ parent[py] = px;
    rank[px]++;
}
 
count--;

}

vector<int>numIsland2(vector<vector<int>> &position,int m, int n){
    int size = m*n;
int count =0;
vector<int>parent(size,-1);
vector<int>rank(size,0);
vector<int>ans;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};
for(auto &dir : position){
    int r =   dir[0];
    int c = dir[1];
    int id = r *n +c;
    if(parent[id] !=  -1){
        ans.push_back(count);
        continue;
    }
    parent[id] = id;
    count++;
    for(int i =0; i<4; i++){
        int dr = r+dx[i];
        int dc = c+dy[i];

 if(dr>=0 && dr<m && dc>=0 && dc<n)
{ 
     int  nid =  dr * n +dc;
     if(parent[nid] != -1){
    dsu(id,nid,parent ,rank ,count);
 }}
    
    }

ans.push_back(count);
}
return ans;
}

int main (){
vector<vector<int>>position = {
    {0,0},{0,1},{1,1},{1,2},{2,1}
};
int m =3,n =3;
vector<int> result = numIsland2(position, m, n);

    for(int x : result)
        cout << x << " ";
return 0;
}