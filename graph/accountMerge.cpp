#include <bits/stdc++.h>
using namespace std;
int findparent(int node,vector<int>&parent){
    if(parent[node] != node){
        parent[node] = findparent(parent[node],parent);
            }
            return parent[node];
}

void dsu(int x,int y,vector<int>&parent){
int px = findparent(x,parent);
int py = findparent(y,parent);
if(px != py){
    parent[py] = px;
}
}
vector<vector<string>>accountMerge(  vector<vector<string>> &account){
    int n = account.size();
    vector<int>parent(n);
    for(int i =0;i<n;i++){
        parent[i] =i;
    }
 unordered_map<string ,int>emailidx;
    for(int i =0;i<n;i++){
        for(int j =1;j<account[i].size();j++){
        string email= account[i][j];

if(emailidx.find(email) == emailidx.end()){
    emailidx[email] = i;
}
else {
dsu(i,emailidx[email],parent);
        }
    }
}
 unordered_map<int,set<string>> merged;
 for(auto &it : emailidx){
    string email = it.first;
    int idx = it.second;

    int parentidx= findparent(idx,parent);
 merged[parentidx].insert(email);
 }
vector<vector<string>>result;
for(auto &it :merged){
    int idx = it.first;
    vector<string> temp;
    temp.push_back(account[idx][0]);

    for(auto &email : it.second)
    temp.push_back(email);
    

    result.push_back(temp);
}
return result;
}



int main(){
    vector<vector<string>>account = {
        {"John","johnsmith@mail.com","john_newyork@mail.com"},{"John","johnsmith@mail.com","john00@mail.com"},{"Mary","mary@mail.com"},{"John","johnnybravo@mail.com"}
    };
vector<vector<string>>a = accountMerge(account);
int i =1;

for(auto &it: a){
    cout << i<<". ";
    for(auto &vec : it){
        cout <<  vec << " ,";
    }
   
    cout << endl;
     i = i+1;
}
    return 0;
}