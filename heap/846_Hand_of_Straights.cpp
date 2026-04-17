#include <bits/stdc++.h>
using namespace std;
bool straight(vector<int> &hand, int size){
int n = hand.size();
map<int,int>mp;
for(int hd : hand){
    mp[hd]++;
}
while (!mp.empty())
{
    int curr = mp.begin() ->first;
    for(int i =0 ;i< size;i++){
       if(mp.find(curr +i) == mp.end())  return false;
    
       mp[curr+i]--;
       if(mp[curr +i] == 0){
        mp.erase(curr +i);
       }
     
    }
}
      return true;
}

int main(){
vector<int> hand ={1,2,3,6,2,3,4,7,8}; int  gpsize = 6;
cout << straight(hand,gpsize) << endl;

return 0;
}