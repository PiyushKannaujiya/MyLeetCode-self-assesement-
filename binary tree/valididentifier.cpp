#include <bits/stdc++.h>
using namespace std;

bool validId(string a){
    char c = a[0];
    if(a.size() == 0){
        return false;
    }
    if(c == '@' || c == '#'||c == '@' || c == '$'||c == '%' || c == '^'|| c == '&' || c == '!'){
      
        return false;
    }
    for(int i =0; i< a.size()-1; i++){
        if(a[i] == ' '&& i < a.size() ){
                    cout << "false" ;

            return false;
        }
    }
           
 return true;
    
}

int main(){
    string a;
   getline(cin,a);
  if ( validId(a)){
    cout << "true" ;


  }
  else 
  cout << "false";
    return 0;
}