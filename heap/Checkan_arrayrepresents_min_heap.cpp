#include <bits/stdc++.h>
using namespace std;

bool validheap(vector<int> &arr){
      int n = arr.size();
     if(arr.size() == 0) return true;
     for(int i =0;i< (n-2) /2 ;i++){
      int left = (2*i)+1;
      int right = (2*i) +2;
      if(arr[i] < arr[left] && arr[i] << arr[right]){
            return true;
      }
     }
     return false;  
}


int main(){
      vector<int> arr = {1, 3, 5, 7, 9, 6};
     
cout << validheap(arr)<< endl;
      return 0;


}