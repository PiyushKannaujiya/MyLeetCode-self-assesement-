#include <bits/stdc++.h>
using namespace std;
int swimInWater(vector<vector<int>>&grid){
    int n = grid.size();
    priority_queue<pair< int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int, pair<int,int>>>>pq;
    vector<vector<bool>>vis(n,vector<bool>(n,false));
    vector<vector<int>>dir = {{-1,0},{1,0},{0,1},{0,-1}};
  pq.push({grid[0][0],{0,0}});
  while(!pq.empty()){
    int time = pq.top().first;
 int x = pq.top().second.first;
 int y = pq.top().second.second;


pq.pop();
if(x == n-1 && y == n-1) return time;
 if(vis[x][y]) continue;

 vis[x][y] = true;
 for(auto &it :dir){
    int i_ = x + it[0];
    int j_  = y + it[1];
    if(i_ >= 0 && j_>=0 && i_< n && j_ < n && !vis[i_][j_] )
 {
 int  ntime = max(time,grid[i_][j_]);
  pq.push({ntime,{i_,j_}});
 }
}


  }
  return -1;

}

int main (){
vector<vector<int>>grid = {
    {0,1},{2,3}
};
int a = swimInWater(grid);
cout << a << endl;

    return 0;
}