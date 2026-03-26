#include <bits/stdc++.h>
using namespace std;

int kth(vector<int>&arr,int k){
priority_queue<int,vector <int>, greater<int>>pq;
for(int x:arr){
    pq.push(x);
}
while (pq.size() >k)
{
   pq.pop();
}
return pq.top();
}

int main(){
      vector<int> arr = {1, 3, 5, 7, 9, 6};
      int k =3;
cout << kth(arr,k)<< endl;
      return 0;


}