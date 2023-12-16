//Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

//You must do it in place.

//TC = O(M*N)
//SC = O(M+N)

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        vector<int>rows(n,1);
        vector<int>cols(m,1);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    rows[i]=0;
                    cols[j]=0;
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(rows[i]==0 || cols[j]==0){
                    matrix[i][j]=0;
                }
            }
        }
     
    }
};






//Optimal Approach
// TC = O(M*N)
// SC = O(1) 

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();
        
        bool rowflag=false;
        bool colflag=false;
     //To check if first row and first coloumn contains any zero.
     //Store if row and col have any 0 in them.
     for(int i=0;i<n;i++){
         for(int j=0;j<m;j++){
             if(i==0 && matrix[i][j]==0){
                 rowflag=true;
             }
             if(j==0 && matrix[i][j]==0){
                 colflag=true;
             }
         }
     }
      
 // Make use of first row and first coloumn as the dummy array 
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
 //If any row or col has 0, make entire row and col as 0
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }
 // Make use of rowflag and colflag in which we stored the status of first row and first col
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(rowflag){
                    matrix[0][j]=0;
                }
                if(colflag){
                    matrix[i][0]=0;
                }
            }

        }

    }
};
