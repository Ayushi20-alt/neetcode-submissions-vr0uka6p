class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = queries.size();

        vector<pair<int, int>>q; // {query, original index}
        for(int i = 0; i < n; i++){
            q.push_back({queries[i], i});
        }

        sort(intervals.begin(), intervals.end());
        sort(q.begin(), q.end());

        // {interval length, right endpoint}
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        vector<int> ans(n, -1);

        int i = 0; // interval pointer
        for(auto &&[query, idx] : q){

            // Add all intervals whose start <= query
            while(i < intervals.size() && intervals[i][0] <= query){
                int left = intervals[i][0];
                int right = intervals[i][1];

                pq.push({right - left + 1, right});
                i++;
            }

            // Remove intervals that cannot contain query
            while (!pq.empty() && pq.top().second < query) {
                pq.pop();
            }

            if (!pq.empty()) {
                ans[idx] = pq.top().first;
            }
        }

        return ans;
    }
};
