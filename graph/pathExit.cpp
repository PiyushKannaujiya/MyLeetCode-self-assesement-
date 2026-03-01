#include <bits/stdc++.h>
using namespace std;

class graph{
    public:
    int v;
    list<int>*l;
    graph(int v){
    this ->v = v;
    l = new list<int>[v];
    }

    void addedge(int u, int v){
        l[u].push_back(v);
         l[v].push_back(u);
    }
    void print(){
       for(int u =0; u<v;u++){
        list <int> neighbour = l[u];
        cout<< u<< " ";
       
       for(int v : neighbour){
         cout << v<< " ";
       }
 cout << endl;    
    }
    
}
};

int main(){
     graph g(5);
    g.addedge(0,1);
        g.addedge(1,2);
    g.addedge(1,3);
    g.addedge(2,3);
    g.addedge(2,4);
    g.print();
}



