#include <bits/stdc++.h>
using namespace std;
int match(string a,string b){
    int n = a.size();
    int m = b.size();
    for(int i =0;i<= n-m;i++){
        int j =0;
        while(j<m && a[i+j] == b[j]){
            j++;
        }
        if(j == m) return i;

    }
    return -1;
}

int main(){
    string text = "banana";
    string pattern = "na" ;
    int a = match(text, pattern);
    cout << a<< endl;
    return 0;
}