class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        map<int,vector<int>> mp;
        vector<int>res;

       //Fill the map using (i+j) technique
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                mp[i+j].push_back(mat[i][j]);
            }
        }


       //Reverse every second value in the map

       bool flip = true;

       for(auto &it : mp){
           if(flip){
               reverse(begin(it.second),end(it.second));
           }

           for(int &num : it.second){
               res.push_back(num);
           }

           flip = !flip;    //We need to reverse every alternate row in map
       }
   
       return res;
        
    }
};
