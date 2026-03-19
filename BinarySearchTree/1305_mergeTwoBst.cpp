#include <bits/stdc++.h>
using namespace std;
class node {
    public:
    int data;
    node *left;
    node *right;
    node(int val){
        this ->data = val;
        left = right =  NULL;
    }
};
node*build(vector<int>&arr , int &y){

    y++;
    if(y>=arr.size() || arr[y] == -1) return NULL;
    node *currnode = new node(arr[y]);
    currnode ->left = build(arr,y);
    currnode ->right = build(arr,y);
    return currnode;
}


 void arrPrint(node *root,vector<int>&ans){
    if(root ==  NULL) return;
  
    if(root ->left) arrPrint(root ->left, ans);
      ans.push_back(root ->data);
    if(root ->right) arrPrint(root ->right, ans);
 }


vector<int> res(node *root1, node *root2){
vector<int>final; int i=0,j=0;
    if(root1 == NULL &&  root2 == NULL) return{};
    vector<int>ans1;vector<int>ans2;
    arrPrint(root1, ans1);
    arrPrint(root2, ans2);
   
 while(i < ans1.size() && j< ans2.size()){
    if(ans1[i]< ans2[j] ){
        final.push_back(ans1[i++]);
    }
    else final.push_back(ans2[j++]);

 }
 while(i < ans1.size()) final.push_back(ans1[i++]);
while(j < ans2.size()) final.push_back(ans2[j++]);   

    return final;
}







int main(){
      vector<int>arr1 = {10,5,3,-1,-1,7,-1,-1};
  vector<int> arr2 =    {15,12,-1,-1,18,-1,-1}; 
    int y1 =-1;
    int y2 = -1;
    node *root1 = build(arr1,y1);
    node *root2 = build(arr2,y2);
vector <int> final =res(root1,root2);
for( auto a: final){
    cout << a<< " ";

}
cout << endl;

 

    return 0;
}