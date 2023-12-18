//Question :
//Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

//Example 1:

//Input: nums = [1,1,1,2,2,3], k = 2
//Output: [1,2]
//Example 2:

//Input: nums = [1], k = 1
//Output: [1]
 


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        int n = nums.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minheap;
        unordered_map<int,int>mp;


       //Store the frequency of elements in map
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }

        for(auto &x : mp){
            minheap.push({x.second,x.first});   //{Frequncy, Elememnt}

            if(minheap.size() > k){
                minheap.pop();
            }
        }
         
         vector<int>res;

         while(!minheap.empty()){
             res.push_back(minheap.top().second);
             minheap.pop();
         }

         return res;

        
    }
};
