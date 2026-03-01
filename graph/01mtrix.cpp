#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> matr(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();
    queue<pair<int, int>> q;

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(mat[i][j] == 0)
           { q.push({i, j});}
        
        else {
            mat[i][j] =-1;
        }
    }
    }
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    while(!q.empty()){
        for(int i = 0; i < q.size(); i++){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx >= 0 && ny >= 0 && nx < m && ny < n && mat[nx][ny] == -1){
                    mat[nx][ny] = mat[x][y] + 1;
                    q.push({nx,ny});
                }
                
            }
        }
    }
    return mat;
}

int main(){
    vector<vector<int>> mat = {
        {0,0,0,},
        {0,1,0},
        {1,1,1}
    };

 vector<vector<int>>a = matr(mat);


    for(auto f : a){
        for(auto b : f){
            cout << b << " ";
        }
        cout << endl;
    }
    return 0;
}
