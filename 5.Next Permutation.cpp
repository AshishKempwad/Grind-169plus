class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int n = nums.size();
        int candidate_index = -1;

        //1)Find the candidate element

        for(int i=n-1;i>0;i--){
            if(nums[i-1]<nums[i]){
                candidate_index = i-1;
                break;
            }   
        }

        //2)Find such an element from right which is greater than candidate element.

        if(candidate_index != -1){   //We do the operation only when we find the candidate_index
            int swap_index = candidate_index;  //Just consider they are same at start

            for(int j=n-1;j>candidate_index;j--){
                if(nums[j]>nums[candidate_index])
                {
                    swap_index = j;
                    break;
                }
            }
            //3)Swap the element at candidate index with the element at swap_index.
            swap(nums[candidate_index],nums[swap_index]);
        }
        //4)Reverse all element from next position from candidate_index

        reverse(nums.begin()+candidate_index+1,nums.end());
    }
};
