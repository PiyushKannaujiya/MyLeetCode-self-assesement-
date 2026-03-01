#include <bits/stdc++.h>
using namespace std;
int numEnclaves(vector<vector<int>>&grid) {
        int n = grid.size();
        int m = grid[0].size();
         queue<pair<int,int>>q;
 for(int i =0;i<n;i++){
    if(grid[0][i] == 1){
        grid[0][i] = 2;
        q.push({0,i});
    }
     if(grid[n-1][i] == 1){
        grid[n-1][i] = 2;
        q.push({n-1,i});
    }
      
 }
 for(int i =0;i<m;i++){
    if(grid[i][0] == 1){
        grid[i][0] = 2;
        q.push({i,0});
    }
     if(grid[i][m-1] == 1){
        grid[i][m-1] = 2;
        q.push({i,m-1});
    }
       }

       int dx[4] = {-1,1,0,0};
       int dy[4] = {0,0,-1,1};
       while(!q.empty()){
        auto[x,y] = q.front();
        q.pop();
        for(int i =0;i<4;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];

        if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny] == 1){
            grid[nx][ny] = 2;
            q.push({nx,ny});
        }
       } }
       int count =0;
       for(int i =0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(grid[i][j] == 1){
          count ++;
            }
        }
       }
       return count;
    }

int main(){
 vector<vector<int >>grid ={{0,0,0,0},{1,0,1,0},{0,1,1,0},{0,0,0,0}};
  int a =numEnclaves(grid);
   cout << a<< endl;
    return 0;
}