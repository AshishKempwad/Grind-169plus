class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>>q;

        int dx[4] = {-1,0,0,1};
        int dy[4] = {0,1,-1,0};

        int fresh_oranges = 0;
//Pushing the locations of all the rotten oranges at the begining
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                if(grid[i][j]==1){
                    fresh_oranges++;
                }
            }
        }


        int timer = -1;  //initialised to -1 since after each step we increment the time by 1 and initially all rotten oranges started at 0.

        while(!q.empty()){
            int size = q.size();

            while(size--){
                pair<int,int> loc = q.front();
                q.pop();

                for(int k=0;k<4;k++){
                    int newx = loc.first + dx[k];
                    int newy = loc.second + dy[k];

                    if(newx>=0 && newx < n && newy>=0 && newy<m && grid[newx][newy]==1){
                        grid[newx][newy]=2;
                        q.push({newx,newy});
                        fresh_oranges--;
                    }
                }
            }

            timer++;
        }

        if(fresh_oranges > 0){   //if fresh>0 that means there are fresh oranges left
            return -1;
        }

        if(timer == -1){ //we initialised with -1, so if there were no oranges it'd take 0 mins.
            return 0;
        }

        return timer;
        
    }
};
