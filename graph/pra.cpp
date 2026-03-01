#include <bits/stdc++.h>
using namespace std;
 void rotate(vector<int> &a, int k){
 for(int i =0; i <=k;i++){
    int d = a[0];
     a.erase(a.begin());
     a.push_back(d);
 }
 for(auto f : a){
    cout  << f<< " ";
 }
 }

int main(){
    vector <int> a = {1,2,3,4,5,6,7};
    int k =1;
     rotate(a,k);
    return 0;
}