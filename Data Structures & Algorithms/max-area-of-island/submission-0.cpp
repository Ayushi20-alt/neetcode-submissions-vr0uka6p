class Solution {
    int directions[4][2] =  {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    int dfs(vector<vector<int>>& grid, int r, int c){
        int m = grid.size();
        int n = grid[0].size();
        int sum = 0;

        if(r < 0 || c < 0 || r >= m || c >= n || grid[r][c] == 0) return 0;
        if(grid[r][c] == 1) sum++;
        grid[r][c] = 0;

        for(int k = 0; k < 4; k++){
            sum += dfs(grid, r + directions[k][0], c + directions[k][1]);
        }

        return sum;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int area = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    int curr = dfs(grid, i, j);
                    area = max(area , curr);
                }
            }
        }

        return area;
    }
};
