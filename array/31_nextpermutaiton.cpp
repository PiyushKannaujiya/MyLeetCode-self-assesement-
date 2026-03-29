#include <bits/stdc++.h>
using namespace std;
vector<int> nextper(vector<int> & arr){
 int n = arr.size();
 int b= -1;
 for(int i = n-1;i>=0;i--){
    if(arr[i-1] < arr[i]){
        b = i-1;
        break;
    }}
    int greateridx = b;
    if(b != -1){
    for(int j =n-1; j>=b +1;j--){
        if(arr[b] < arr[j]){
            greateridx = j;
            swap(arr[b], arr[j]);
            break;
        }
    }
    }

    reverse(arr.begin() + greateridx+1, arr.end());
    
return arr;

 }
 
int main(){
    vector<int> arr = {1,3,2};
vector <int>a = nextper(arr);
 for(auto b: a){
    cout <<b<< " ";

 }
 cout << endl;

    return 0;
}