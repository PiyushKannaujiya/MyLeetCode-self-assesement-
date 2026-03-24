#include <bits/stdc++.h>
using namespace std;
int ans(vector<int> arr){
 if(arr.size() == 0) return -1;// binary search 
int l =0, r = arr.size()-1;
while (l<r){
    int mid = l+ (r-l)/2;

    bool isEven ;
    if( (r -mid )% 2 == 0){
        isEven = true;
    }
    else {
        isEven = false;
           }

     if(arr[mid ] == arr[mid+1]){
        if(isEven){
         l = l+2;    
        }
        else {
       r= mid-1;   
     }
    }
    else {
  if(isEven){
        r = mid;
        }
        else {
        l= l+1;
     }

     }
        


}
return arr[r];


}

int main(){
    vector<int> arr = {1,1,2,3,3,4,4,8,8};
 int a = ans(arr);
  cout << a<< endl;

}