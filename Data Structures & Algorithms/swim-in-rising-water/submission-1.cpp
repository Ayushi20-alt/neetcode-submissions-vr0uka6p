class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
          int n = grid.size();

        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;
         vector<vector<int>> vis(n, vector<int>(n, 0));

        // {time, row, col}
        pq.push({grid[0][0], 0, 0});
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            int time = curr[0];
            int row = curr[1];
            int col = curr[2];

            if (vis[row][col]) continue;
            vis[row][col] = 1;

            if (row == n - 1 && col == n - 1)
                return time;

            for (int k = 0; k < 4; k++) {
                int nrow = row + delrow[k];
                int ncol = col + delcol[k];

                if (nrow >= 0 && nrow < n &&
                    ncol >= 0 && ncol < n &&
                    !vis[nrow][ncol]) {

                    pq.push({
                        max(time, grid[nrow][ncol]),
                        nrow,
                        ncol
                    });
                }
            }
        }

        return -1;
    }
};
