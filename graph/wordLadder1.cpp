#include <bits/stdc++.h>
using namespace std;
 int ladderLength(vector<string> wordList,string s,string e){
   
    unordered_set<string> dict(wordList.begin(),wordList.end());
    if(dict.find(e) == dict.end()){
        return 0;
    }W
    queue<string> q;
    q.push(s);
    dict.erase(s);
     int count =1;
  while(!q.empty()){
    int sz = q.size();
    while(sz--){
        string word = q.front();
        q.pop();
        if(word == e){
            return count;
        }
        for(int i =0;i<word.size();i++){
            char org = word[i];
         
            for(char ch ='a';ch <='z';ch++){
                word[i]= ch;
                if(dict.find(word) != dict.end() ){
                    q.push(word);
                    dict.erase(word);
                }
                word[i] = org;
            }
        }
      
    }

 count ++; 
  } 
  return count;  
 }

int main (){
   string beginWord = "hit";
   string endWord = "cog";
   vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
     int a = ladderLength(wordList,beginWord,endWord);
     cout << a<< endl; 
    return 0;
}