class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int oldColor = image[sr][sc];
        queue<pair<int,int>>q;
        q.push({sr,sc});
        vis[sr][sc]=true;
        image[sr][sc]=color;

        vector<int>dx = {0,1,-1,0};
        vector<int>dy = {1,0,0,-1};

        while(!q.empty()){
            int sr = q.front().first;
            int sc = q.front().second;
             q.pop();

           for(int k=0;k<4;k++){
               int new_sr = sr + dx[k];
               int new_sc = sc + dy[k];
             
                if(new_sr >= 0 && new_sr < n && new_sc >=0 && new_sc < m && image[new_sr][new_sc]==oldColor && vis[new_sr][new_sc]==false){

                    vis[new_sr][new_sc]=true;
                    q.push({new_sr,new_sc});
                    image[new_sr][new_sc]=color;

                }
           }

        }

        return image;
        
    }
};
