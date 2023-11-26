class Solution {
public:

    int threeSumClosest(vector<int>& nums, int target) {

        int n = nums.size();
        int closest_num = 100000;

        sort(begin(nums),end(nums));

        for(int k=0;k<n-2;k++){

            int i = k+1;
            int j = n-1;

            while(i<j){
                int sum = nums[i]+nums[j]+nums[k];

               if(abs(target-sum) < abs(target-closest_num))
                   closest_num = sum;

                if(sum > target){
                    j--;
                }
                else{
                    i++;
                }
            }

        }

        return closest_num;

    }
};
