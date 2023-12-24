class Solution {
public:

    int findLastOccurance(vector<int>& nums,int target, int n){
        int l = 0;
        int h = n-1;
        int temp = -1;
        while(l<=h){
            int mid = l + (h - l)/2;
            if(nums[mid]==target){
                temp = mid;
                l = mid+1;
            }
            else if(nums[mid] < target){
                l = mid+1;
            }
            else{
                h = mid-1;
            }
        }
        return temp;
    }

    int findFirstOccurance(vector<int>& nums,int target, int n){
        int l = 0;
        int h = n-1;
        int temp = -1;

        while(l<=h){
            int mid = l + (h - l)/2;
            if(nums[mid]==target){
                temp = mid;
                h = mid-1;
            }
            else if(target > nums[mid]){
                l = mid+1;
            }
            else{
                h = mid-1;
            }
        }

        return temp;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
         int n = nums.size();
         vector<int>res;
         int first = findFirstOccurance(nums,target,n);
         int last = findLastOccurance(nums,target,n);

         res.push_back(first);
         res.push_back(last);
         return res;
        
    }
};
//Story:
  //Find 1st occurance
        //Find last occurance
        //Whenever it is given as sorted array, we need to think in terms of binary search
        //We will maintain a variable that will be updated to find 1st and last occurance
        //In 1st occurance, if we find the element, we will move to left to check for 1st occurance
        //In last occurance, we will move towards right even if we find the ele for last occurance
