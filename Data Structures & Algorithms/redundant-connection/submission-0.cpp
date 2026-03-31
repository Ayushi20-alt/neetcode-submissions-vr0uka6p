class Solution {
public:
    bool dfs(int src, int target, vector<vector<int>>& adj, vector<int>& vis){
        vis[src] = true;
        if(src == target) return true;

        for(int &it : adj[src]){
            if(vis[it]) continue;
            if(dfs(it, target, adj, vis)) return true;
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        vector<vector<int>> adj(n + 1);

        for (auto& it : edges) {
            int u = it[0];
            int v = it[1];

            vector<int> vis(n + 1, 0);
            if (!adj[u].empty() && !adj[v].empty() && dfs(u, v, adj, vis)) {
                return {u, v};
            }

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return {};
    }
};
