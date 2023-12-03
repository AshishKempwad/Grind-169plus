class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        //1)Take the transpose of an image

        int m = matrix.size();
        int n = matrix[0].size();

        for(int i=0;i<m;i++){
            for(int j=i;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);   //swap diagonal elements with each other
            }
        }

      //2)Reverse the rows
        for(int i=0;i<m;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
        
    }
};
