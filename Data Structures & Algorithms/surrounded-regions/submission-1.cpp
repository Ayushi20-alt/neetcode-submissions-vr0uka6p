class Solution {
public:
    int directions[4][2] = {{1,0}, {-1,0}, {0, -1}, {0, 1}};
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>>vis(m, vector<int>(n, 0));

        // traverse first row and last row
        for(int j = 0; j <n; j++){
            // first row
            if(!vis[0][j] && board[0][j] == 'O'){
                dfs(0, j, vis, board);
            }
            // last row
            if(!vis[m-1][j] && board[m-1][j] == 'O'){
                dfs(m-1, j, vis, board);
            }
        }

        // traverse first col and last col
        for(int i = 0; i < m; i++){
            // first col
            if(!vis[i][0] && board[i][0] == 'O'){
                dfs(i, 0, vis, board);
            }

            // last col
            if(!vis[i][n-1] && board[i][n-1] == 'O'){
                dfs(i, n-1, vis, board);
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!vis[i][j] && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }

    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& board){
        vis[row][col] = 1;
        int m = board.size();
        int n = board[0].size();

        for(int i = 0; i < 4; i++){
            int r = row + directions[i][0];
            int c = col + directions[i][1];

            if(r >=0 && r < m && c >= 0 && c < n && !vis[r][c] && board[r][c] == 'O'){
                dfs(r, c, vis, board);
            }
        }
    }
};
