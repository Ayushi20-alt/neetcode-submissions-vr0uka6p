class Solution {
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(m == 0 || n == 0) return;

        queue<pair<int, int>>q;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n;j++){
                if(grid[i][j] == 0) q.emplace(i, j);
            }
        }

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;

            q.pop();
            for(int k = 0; k < 4; k++){
                int x = r + directions[k][0];
                int y = c + directions[k][1];
                if(x < 0 || y < 0 ||x >= m || y >= n || grid[x][y] != INT_MAX){
                    continue;
                }
                grid[x][y] = grid[r][c] + 1;
                q.emplace(x, y);
            }
        }
    }
};
