#include <bits/stdc++.h>
using namespace std;
bool canJump(vector<int>& nums){
   int reach =0;

         for(int i =0;i<nums.size();i++){
 if(i>reach) return false;
        int a = nums[i];

        for(int j=1;j<=a;j++)
     {
      reach = max(reach, i+j) ;
   }
        if( reach >= nums.size()-1){
            return true;
          }
        
     }
     return false;
} 
int main(){
 vector<int>v = {3,2,1,0,4};
 cout << canJump(v)<< endl;

    return 0;
}