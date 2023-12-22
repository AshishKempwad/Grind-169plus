class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        unordered_map<int,vector<pair<int,int>>> adj;

        for(auto &f : flights){
            int u = f[0];
            int v = f[1];
            int cost = f[2];

            adj[u].push_back({v,cost}); 
        }

        //Apply BFS
        queue<pair<int,int>>q;
        q.push({src,0});   //{src,cost} Initially we put cost of going from src to src as 0.
        vector<int>dist(n,INT_MAX);  //Initially cost to reach all nodes in infinity.
        dist[src]=0;
        int steps=0;

        while(!q.empty() && steps <= k){
            int size = q.size();
            while(size--){
                int u = q.front().first; //src node
                int d = q.front().second; //cost to cover the distance

                q.pop();

                for(auto &P : adj[u]){
                    int v = P.first;
                    int cost = P.second;

                    if(dist[v] > d + cost){  //Cost till u + Cost from u to v
                        dist[v] = d + cost;

                        q.push({v,d+cost});
                    }
                }
            }

            steps++;
        }

        if(dist[dst] == INT_MAX){
            return -1;
        }

        return dist[dst];
    }
};
