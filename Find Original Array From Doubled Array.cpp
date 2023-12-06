class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
     
     int n = changed.size();
     unordered_map<int,int> mp;
     //  <KEY>         <VALUE>
     // <ELEMENT>    <FREQUENCY>
     if(n % 2 != 0)   //If the length is odd, then it is not doubled array, hence cant find original array. Return empty array
     {
         return {};
     }

     //sort the changed array
//We sort the changed array so that we just have to worry about doubling and checking rather than checking for half if the bigger number was present before
     sort(begin(changed),end(changed));  

     // add freq into the map
     for(int &num : changed){
         mp[num]++;
     }
     
     vector<int> res;

     for(int &num : changed){

         if(mp[num]==0){
             continue;    //skip
         }

         int twice = num * 2;

         if(mp.find(twice)==mp.end() || mp[twice]==0){
             return {};
         }

         res.push_back(num);
         mp[num]--;
         mp[twice]--;
     }

     return res;
        
    }
};
