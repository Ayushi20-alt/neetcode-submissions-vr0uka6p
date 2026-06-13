class Solution {
public:
    void dfs(int i, int j , vector<vector<char>>& board, vector<vector<int>>& vis){
        vis[i][j] = 1;
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        for(int k = 0; k < 4; k++){
            int nrow = i + delrow[k];
            int ncol = j + delcol[k];

            if(nrow >= 0 && ncol >= 0 && nrow < board.size() && ncol < board[0].size()
            && board[nrow][ncol] == 'O' && !vis[nrow][ncol]){
                dfs(nrow, ncol, board, vis);
            } 
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));

        // traverse first row and last row 
        for(int j = 0; j < n; j++){
            if(board[0][j] == 'O' && !vis[0][j]){
                dfs(0, j, board, vis);
            }
            if(board[m-1][j] == 'O' && !vis[m-1][j]){
                dfs(m-1, j, board, vis);
            }
        }

        // traverse first col and last col
        for(int i = 0; i < m; i++){
            if(board[i][0] == 'O' && !vis[i][0]){
                dfs(i, 0, board, vis);
            }
            if(board[i][n-1] == 'O' && !vis[i][n-1]){
                dfs(i, n-1, board, vis);
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
};
