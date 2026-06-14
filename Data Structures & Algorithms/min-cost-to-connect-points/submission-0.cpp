class Solution {
public:
    int manDist(vector<vector<int>>& points, int p1, int p2){
        return abs(points[p1][0] - points[p2][0]) + abs(points[p1][1] - points[p2][1]);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        // {weight, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        int n = points.size();
        vector<int>mstSet(n, 0);
        int mstCost = 0;

        pq.push({0, 0});

        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            int wt = p.first;
            int node = p.second;

            if(mstSet[node] == 1) continue;
            mstSet[node] = 1;
            mstCost += wt;

            for(int i = 0; i < n; i++){
                if(mstSet[i] == 0){
                    int dist = manDist(points, node, i);
                    pq.push({dist, i});
                }
            }
        }

        return mstCost;
    }
};
