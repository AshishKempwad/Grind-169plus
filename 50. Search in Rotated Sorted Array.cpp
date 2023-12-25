class Solution {
public:

    int binarySearch(vector<int>& nums, int target, int l, int h){
        while(l<=h){
            int mid = l+(h-l)/2;
            if(nums[mid]==target){
                return mid;
            }else if(nums[mid]>target){
                h=mid-1;
            }else{
                l=mid+1;
            }
        }

        return -1;
    }

    int findMinEleIndex(vector<int>& nums){
        //Minimum Element would have both its neighbours bigger that it
        int n=nums.size();
        int l = 0;
        int h = n-1;

        while(l<=h){
            if(nums[l]<=nums[h]){ //If nums[l]<nums[h], that means array is sorted without any rotation,hence smallest element would be at 1st index
                return l;    
            }

            int mid = l+(h-l)/2;
            int prev = (mid+n-1)%n;
            int next = (mid+1)%n;

            if(nums[mid]<=nums[prev] && nums[mid]<=nums[next]){
                return mid; //Returning the index of minimum element
            }
            else if(nums[l]<=nums[mid]){
                //Left side is sorted, so check for minimum element in right side
                l=mid+1;
            }else if(nums[mid]<=nums[h]){
                //Right is sorted, hence search for minimum element in left side
                h=mid-1;
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int minIndex = findMinEleIndex(nums);
        int res1 = binarySearch(nums,target,0,minIndex-1);
        int res2 = binarySearch(nums,target,minIndex,n-1);

        if(res1==-1){
            return res2;
        }else{
            return res1;
        }
        
    }
};
