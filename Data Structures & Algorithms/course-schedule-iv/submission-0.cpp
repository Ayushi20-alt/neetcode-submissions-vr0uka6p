class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, 
    vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // build a adjacency list first
        vector<vector<int>> adj(numCourses);
        int indegree[numCourses] = {0};
        for(auto it : prerequisites){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int>q;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0) q.push(i);
        }

        vector<int>topo;
        unordered_map<int, unordered_set<int>>mpp;
        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it : adj[node]){
                mpp[it].insert(node);
                // find the prerequiste of node as well
                for(auto &preq : mpp[node]){
                    mpp[it].insert(preq);
                }
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }

        int Q = queries.size();
        vector<bool> result(Q, false);
        for(int i = 0; i < Q; i++){
            int src = queries[i][0];
            int dest = queries[i][1];

            bool reachable = mpp[dest].contains(src);
            result[i] = reachable;
        }

        return result;
    }
};