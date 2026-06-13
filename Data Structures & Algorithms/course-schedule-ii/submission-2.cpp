class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // adjacency list
        vector<vector<int>>adj(numCourses);
        for(auto it : prerequisites){
            int u = it[0];
            int v = it[1];
            adj[v].push_back(u);
        }

        // indegree calculation
        vector<int>indegree(numCourses, 0);
        for(int i = 0; i < numCourses; i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }

        // find out if we have indegree as 0
        queue<int>q;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0) q.push(i);
        }

        // now calculate the topo ordering
        vector<int>topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }

        if(topo.size() != numCourses) return {};

        return topo;
    }
};
