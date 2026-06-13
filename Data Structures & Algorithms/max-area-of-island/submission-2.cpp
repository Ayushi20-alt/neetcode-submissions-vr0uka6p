class Solution {
public:
    void dfs(int row, int col, int &count, vector<vector<int>>&vis, 
    vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        vis[row][col] = 1;
        count++;

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        for(int i = 0; i < 4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol] == 1 
            && !vis[nrow][ncol]){
                dfs(nrow, ncol, count, vis, grid);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int area = 0;
        vector<vector<int>>vis(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int count = 0;
                if(grid[i][j] == 1 && !vis[i][j]){
                    dfs(i, j, count, vis, grid);
                    area = max(area, count);
                }
            }
        }
        return area;
    }
};
