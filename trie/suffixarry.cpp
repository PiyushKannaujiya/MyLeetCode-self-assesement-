#include <bits/stdc++.h>
using namespace std;
 
vector<int > suffix(string s){
int n = s.size();
vector<int>suff;
vector<pair <string, int>>st;
for(int i =0;i<n;i++){
st.push_back({s.substr(i),i});
}
sort(st.begin(),st.end());
for(auto a : st)
{
    cout << a.first<< " :" << a.second<<" " << endl;
    suff.push_back(a.second);
}

return suff;
}


int main(){
 string s = "banana";
 vector <int>a = suffix(s);
 for(auto b:a){
    cout <<b << " ";
 }
cout << endl;
    return 0;
}