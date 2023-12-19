class Solution {
public:

    int dx[4] = {-1,0,0,1};
    int dy[4] = {0,1,-1,0};


    void dfs(vector<vector<char>>& grid, int x, int y, int n, int m){
        grid[x][y]='2';

        for(int k=0;k<4;k++){
            int newx = x + dx[k];
            int newy = y + dy[k];

            if(newx >= 0 && newx < n && newy >= 0 && newy < m && grid[newx][newy]=='1'){
                dfs(grid,newx,newy,n,m);
            } 
        }
        
    }


    int numIslands(vector<vector<char>>& grid) {

        int count = 0;
        int n = grid.size();
        int m = grid[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){                  
                    dfs(grid,i,j,n,m);
                    count++;
                }
            }
        }

        return count;
        
    }
};


