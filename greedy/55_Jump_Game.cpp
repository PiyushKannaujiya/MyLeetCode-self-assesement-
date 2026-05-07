#include <bits/stdc++.h>
using namespace std;
bool canJump(vector<int>& nums){
   int reach =0;

         for(int i =0;i<nums.size();i++){

        int a = nums[i];
        
        for(int j=1;j<=a;j++)
     {
         i = j+ i;
        if(i == nums.size()-1){
            return true;
            break;}
        }
     }
     return false;
} 
int main(){
 vector<int>v = {3,2,1,0,4};
 cout << canJump(v)<< endl;

    return 0;
}