class Solution {
public:

    vector<int>topologicalSort(unordered_map<int,vector<int>> &adj,vector<int>&indegree, int n){
        queue<int>q;
        int count=0;
        vector<int>res;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
                count++;
                res.push_back(i);
            }
        }

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(auto &v : adj[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                    count++;
                    res.push_back(v);
                }
            }
        }

        if(count == n){
            return res;    //There is no cycle hence we are able to visit all the nodes and return the res[Able to complete all courses]
        }

        return {};  //Not able to complete all courses

    }
   
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indegree(numCourses,0);
        unordered_map<int,vector<int>> adj;

        for(auto &ele : prerequisites){
            int a = ele[0];
            int b = ele[1];

            adj[b].push_back(a);   // b-->a [In order to complete course b, we need to first complete course a]
            indegree[a]++;
        }

        return topologicalSort(adj,indegree,numCourses);
    }
};
