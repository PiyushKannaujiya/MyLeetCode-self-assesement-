#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<string> word ={"flower","flow","light"};
   
    string ans = word[0];
    for(int i =1;i< word.size();i++){
             string res = "";
       for(int j =0;j<word[i].size() && j<ans.size();j++){
        if(ans[j] == word[i][j]){
            res += ans[j];
        }
        else {
            cout << "no word"<< endl;
        break;
          }
       }
           ans = res;

    }
    cout << ans << endl;
    return 0;
}