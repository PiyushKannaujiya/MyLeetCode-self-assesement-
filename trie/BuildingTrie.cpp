#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    unordered_map<char, node*>children;
    bool endOfWord;
    node (){
        endOfWord = false;
    }
};

class trie{
    node *root; 

    public :
    trie(){
        root = new node();
    }

  void insert(string key){
    node *temp = root;
    for(int i =0; i<key.size() ;i++){
        if(temp ->children[key[i]] == 0){
            temp ->children[key[i]] = new node();

        }
        temp =  temp ->children[key[i]];
    }
    temp ->endOfWord = true;

  }
  bool search(string key){
    node* temp = root;
    for(int i = 0; i<key.size(); i++){
        if(temp ->children.count(key[i])){
            temp = temp->children[key[i]];
        }
        else return false;

    }
    return temp ->endOfWord;
  } 
};

int main (){
    trie t;
    vector <string> words = {"the","a","there","their","any","thee"};
    for(int i =0; i<words.size(); i++){
        t.insert(words[i]);

    }
    cout << t.search("a");
    return 0;
}