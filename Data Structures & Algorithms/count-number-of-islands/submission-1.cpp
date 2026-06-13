class Solution {
public:
    void solve(int i , int j , vector<vector<int>>& vis, vector<vector<char>> &grid){
        vis[i][j] = 1;
        queue<pair<int, int>>q;
        q.push({i, j});
        int m = grid.size();
        int n = grid[0].size();

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int k = 0; k < 4; k++) {
                int nrow = row + delRow[k];
                int ncol = col + delCol[k];

                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && !vis[nrow][ncol] 
                && grid[nrow][ncol] == '1'){
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int count = 0;
        vector<vector<int>>vis (m, vector<int>(n, 0));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(vis[i][j] != 1 && grid[i][j] == '1'){
                    count++;
                    solve(i, j, vis, grid);
                }
            }
        }

        return count;
    }
};
