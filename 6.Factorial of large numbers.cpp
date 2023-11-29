//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:

   void multiply(vector<int>&arr, int &size, int multiplier){
       int carry = 0;
       
       for(int i=0;i<size;i++){
           int res = multiplier * arr[i];
           res = res+carry;
           
           arr[i] = res%10;   //storing the reminder
           carry = res/10;
           
       }
       
       while(carry > 0){  ///carry could also be large
           arr[size] = carry%10;
           size++;
           carry = carry/10;
       }
   }


    vector<int> factorial(int N){
       vector<int>arr(10000,0);
       int size =1;
       
       arr[0]=1;  // Storing 1 in first block
       for(int multiplier = 2; multiplier <= N; multiplier ++){
           multiply(arr,size,multiplier);
       }
       
       vector<int>result;
       for(int i=size-1;i>=0;i--){
           result.push_back(arr[i]);
       }
       return result;
    }
};
