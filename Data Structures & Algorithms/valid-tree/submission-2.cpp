class Solution {
public:
    bool dfs(int node, int parent , vector<vector<int>>&adj, vector<int>& vis){
        vis[node] = 1;
        for(auto it : adj[node]){
            if(it == parent) continue;
            if(vis[it]) return false;
            if(!dfs(it, node, adj, vis)) return false;
        }
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        // maintain the prev node and vis array and if no cycle then its a tree
        if(n == 0) return true;
        if(edges.size() != n-1) return false;

        vector<vector<int>>adj(n);
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int>vis(n, 0);
        // check for cycle
        if(!dfs(0, -1, adj, vis)) return false;

        // connectivity check
        for(int i = 0; i < n; i++){
            if(!vis[i]) return false;
        }
        return true;
    }
};
