#include <bits/stdc++.h>


// this is o(n^4) but we can solve this using o(n^2) if we first dfs the cell having 1 and we store the group now if and 0 is converted we just have to just add.

using namespace std;
vector<vector<int>> direction = {{-1,0},{1,0},{0,-1},{0,1}};
int n;
int dfs(vector<vector<int>>&grid,int i,int j,vector<vector<bool>>&vis){
if(i >=n|| j>=n || i<0 || j<0 || grid[i][j] == 0 || vis[i][j]){
return 0;
}
vis[i][j] = true;
int count =1;
for(vector<int> &dir :direction){
    int i_ = i +dir[0];
    int j_ =j+dir[1];


    count += dfs(grid,i_,j_,vis);
}
return count;

}
int largeIsland(vector<vector<int>>&grid){
  n= grid.size();
  int maxArea = 0;

    for(int i =0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j] == 0){
                grid[i][j] =1;
            
       vector<vector<bool>>vis(n,vector<bool>(n,false));
        int largestisland = 0;
        for(int x =0;x<n;x++){
            for(int y =0;y<n;y++){
                if(grid[x][y] == 1 && !vis[x][y]){
                    largestisland = max(largestisland,dfs(grid,x,y,vis));
                }
            }
        }
 maxArea = max(maxArea,largestisland);
 grid[i][j] =0;
        
 


                    }
                }
            }
            return maxArea== 0? n*n : maxArea;
        }
    

int main(){
 vector<vector<int>>grid= {
    {1,1},{1,0}
 };
int a = largeIsland(grid);
cout << a << endl;
    return 0;
}