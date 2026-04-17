#include <bits/stdc++.h>
using namespace std;
struct comp {
    bool operator() (pair<int,int>a,pair<int,int>b){
        return a.second > b.second;
    }};


 vector<int> topK(vector<int> &nums,int k){
    vector<int>res;
    int  n= nums.size();
if(n ==0) return {};
unordered_map<int,int>mp;
for(int b : nums){
    mp[b]++;
}

priority_queue<pair<int,int>,vector<pair <int,int>> ,comp>pq;
for(auto &m :mp){
           pq.push(m);
             if(pq.size() >k){
        pq.pop();
    }
    }
  

while(!pq.empty()){
    res.push_back(pq.top().first);
    pq.pop();
}
return res;
 }

int main(){
vector<int> nums = {1,1,1,2,2,3}; int k = 2;
vector<int>a = topK(nums,k);
for(int b :a){
    cout << b << " ";
}
cout << endl;
    return 0;
}