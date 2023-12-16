
//TC O(n)
//SC O(n)
//Using prefix product and suffix product

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefixProduct(n);
        vector<int>suffixProduct(n);

        prefixProduct[0]=1;
        suffixProduct[n-1]=1;


        for(int i=1;i<n;i++){
            prefixProduct[i] = nums[i-1] * prefixProduct[i-1];
        }

        for(int i=n-2;i>=0;i--){
            suffixProduct[i] = suffixProduct[i+1] * nums[i+1];
        }

        vector<int>res(n);

        for(int i=0;i<n;i++){
            res[i] = prefixProduct[i]*suffixProduct[i];
        }

        return res;
    }
};




//Optimizing space
//TC O(n)
//SC O(1)  ----Not considering result vector in space complexity.
//We dont maintain seperate vectors for prefix product and suffix product. we do that in the res vector itself.

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>res(n,1);

        int curr=1;

        for(int i=0;i<n;i++){
            res[i]=res[i]*curr;
            curr=curr*nums[i];
        }

        curr =1;
        for(int i=n-1;i>=0;i--){
            res[i]=res[i]*curr;
            curr=curr*nums[i];
        }

        return res;
    }
};
