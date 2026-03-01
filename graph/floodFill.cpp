#include <bits/stdc++.h>
using namespace std;
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int ntcolor =0;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(image[i][j]==1){
                    ntcolor++;
                }
            }
        }
       int dx[4] = {-1,1,0,0};
       int dy[4] = {0,0,-1,1};
       queue<pair<int ,int>>q;
       q.push({sr,sc});
       int dx[4]= {-1,1,0,0};
    int dy[4]={0,0,-1,1};
 while (!q.empty())
 {

    for(int i=0; i<q.size();i++){
        int x = q.front().first;
        int y = q.front().second;
        image[x][y]= color;
        ntcolor--;
       int nx= x+dx[i];
       int ny = y+dy[i];
   q.push({nx,ny});

    }
 }
 return ntcolor == 0

    }


int main(){
vector<vector<int,int>>image = {
    {1,1,1},
    {1,1,0},
    {1,0,1}
};int sr, sc, color;
cin >> sr,sc,color;

vector<vector<int>> a = floodFill(image,1,1,color);
 for(auto row: a){
    for(auto val:row){
        cout << val<< " ";
    }
    cout << endl;
 }
    return 0;
}