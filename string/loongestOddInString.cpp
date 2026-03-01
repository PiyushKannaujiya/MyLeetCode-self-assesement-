#include <bits/stdc++.h>
using namespace std;

int main(){
    string a = "5427";
    int n = a.size();
    string d ="";
    for(int i =0;i<n;i++){
        int b = a[i] - '0';
        if(b%2 != 0 ){
            d +=a[i];
        }

    }
    int ans = stoi(d);
    cout << ans << endl;

}