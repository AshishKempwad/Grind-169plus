class Solution {
public:

     vector<vector<int>>results;

     void twoSum(vector<int>&nums, int target, int i, int j){

         while(i<j){
             if(nums[i]+nums[j] > target){
                 j--;
             }
             else if(nums[i]+nums[j] < target){
                 i++;
             }
             else{

                 //We have found the pair
                 //We need to remove the duplicates from either of the side
                 while(i<j && nums[i]==nums[i+1]){
                     i++;
                 }
                 while(i<j && nums[j]==nums[j-1]){
                     j--;
                 }

                 results.push_back({-target,nums[i],nums[j]});
                  i++;
                  j--;
             }

         }
     }



    
    vector<vector<int>> threeSum(vector<int>& nums) {
        //n1+n2+n3=0
        
        int n = nums.size();

        if(n<3){
            return {};
        }
        results.clear();

        //1)Sort
        sort(begin(nums),end(nums));

        //2)Fixing one element as target(n1)
     
        for(int i=0;i<n-2;i++){
            //Need to avoid duplicates in the target
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }

            int target = -(nums[i]);

            twoSum(nums,target,i+1,n-1);  //it will return us n2,n3

        }

        return results;
    }
};
