class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size();  //rows
        int n = mat[0].size(); //col

        unordered_map<int,vector<int>> mp;

        //Store the diagonal elements in map using(i-j)

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                mp[i-j].push_back(mat[i][j]);
            }
        }

        //Sort the each value in the map

       for(auto &it : mp){
           sort(begin(it.second),end(it.second));

       }


       //Store the values back into matrix

       for(int i = m-1; i >= 0; i--){
           for(int j = n-1; j >= 0; j--){
               mat[i][j] = mp[i-j].back();   //inserting from back

               mp[i-j].pop_back();
           }
       }

      return mat;
    }
};
