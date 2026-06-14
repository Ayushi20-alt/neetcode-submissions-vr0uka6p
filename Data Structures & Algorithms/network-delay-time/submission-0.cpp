class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>>adj(n + 1);
        for(auto it : times){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v, w}); // node, dist
        }

        // dist, node;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        pq.push({0, k});

        vector<int> dist(n + 1, 1e9);
        dist[k] = 0;

        int time = 0;

        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (dis > dist[node]) continue;

            for(auto it : adj[node]){
                int edgeWeight = it.second;
                int adjNode = it.first;

                if(edgeWeight + dis < dist[adjNode]){
                    dist[adjNode] = edgeWeight + dis;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        for(int i = 1; i <= n; i++){
         if(dist[i] == 1e9) return -1;
    time = max(time, dist[i]);
}

        return time;
    }
};
