#include <bits/stdc++.h>
using namespace std;

int taskschduler(vector<string>task, int n){
vector <int> mp(26,0);
 for(string ch :task){
    mp[ch[0] - 'A']++;
 }  
  priority_queue<int> pq;
  for(int i =0;i<26;i++){
    if(mp[i]>0){
        pq.push(mp[i]);
    }
  }
int time =0;
while(!pq.empty()){
    vector<int>temp;

    for(int i =1;i<= n+1;i++){
        if(!pq.empty()){
        int freq = pq.top();
      pq.pop();
      freq --;
      temp.push_back(freq);
    }
}
for( int &f :temp){
    if(f >0){
       pq.push(f);
    }
}
if(pq.empty()){
     time += temp.size();
}
else {
 time += n+1;
}

 }
 return time;
}


int main(){
vector<string>task = {"A","A","A","B","B","B"} ;
int n = 2  ;
 int a =taskschduler( task, n);
cout << a<< endl;
    return 0;
}