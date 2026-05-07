#include <bits/stdc++.h>
using namespace std;
 bool checkValidString(string s){
stack <int>open,astrik;
 for(int i =0;i<s.size();i++){
    if(s[i] == '('){
        open.push(i);
    }
    else  if(s[i] == '*'){
        astrik.push(i);
    }
   else if(s[i] = ')'){
     if(!open.empty()){
        open.pop();
     }
     else if(!astrik.empty()){
        astrik.pop();
     }
     else return false;
   }

 }
while(!open.empty() && !astrik.empty()){
    if(open.top()> astrik.top()){
      return false;
    }
    else {
        astrik.pop();
        open.pop();
    }
}
return open.empty();


 }


int main(){
    string s = "*()()*)(";
cout <<  checkValidString( s)<< endl;

    return 0;
}
