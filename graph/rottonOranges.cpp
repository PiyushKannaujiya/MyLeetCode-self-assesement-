#include <bits/stdc++.h>
using namespace std;
int rottenOranges(vector<vector<int>>&grid){
int n = grid.size();
int m = grid[0].size();
queue<pair<int,int>>q;
int fresh =0;

for(int i=0; i<n;i++){
    for(int j=0;j<m;j++){
       if(grid[i][j] == 2){
         q.push({i,j});
       }
       else {
        if(grid[i][j] == 1)
       { fresh++;
    }
       }
    }
    }


  int min =0;
    int dx[4]= {-1,1,0,0};
    int dy[4]={0,0,-1,1};
    
     while(!q.empty()){
int size = q.size();
min++;
for(int i =0;i< size;i++){
        int x= q.front().first;
        int y = q.front().second;
        q.pop();

 for(int i=0;i<4;i++)  {     
int nx = x +dx[i];
int ny = y+dy[i];  

if(nx>= 0 && ny>= 0 && nx <n && ny <m && grid[nx][ny] == 1){
grid[nx][ny] = 2;
    fresh--;
    q.push({nx, ny});
}}
     }
    } 
 return  fresh == 0 ? min:-1;


}

int main(){
    vector<vector<int>>grid= {
      {2,1,1},
      {1,1,1},
     {1,0,1}
    };
    cout << rottenOranges(grid)<< endl;
    return 0;

}
