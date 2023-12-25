class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        //Start searching from top right corner(Every times we move either down or left depending on the condition)
        //Worst Case TC = O(m+n)

        int i = 0;
        int j = m-1;
        while(i<n && j>=0){
            if(matrix[i][j] == target){
                return true;  //We find the target element
            }else if(matrix[i][j] > target){
                //Target is smaller hence we move left, by decreasing j
                j--;
            }else{
                //If target is larger than element, we move down by increasing i
                i++;
            }
        }

        return false; //If we dont find the target element in the matrix
    }
};
