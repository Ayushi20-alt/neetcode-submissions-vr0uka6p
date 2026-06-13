class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(m == 0 || n == 0) return;

        queue<pair<int, int>>q;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0) q.emplace(i, j);
            }
        }

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            int delrow[] = {-1, 0, 1, 0};
            int delcol[] = {0, 1, 0, -1};
            for(int i = 0; i < 4; i++){
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];

                if(nrow < 0 || nrow >= m || ncol < 0 || ncol >= n || 
                grid[nrow][ncol] != INT_MAX){
                    continue;
                }

                grid[nrow][ncol] = grid[r][c] + 1;
                q.emplace(nrow, ncol);
            }
        }
    }
};
