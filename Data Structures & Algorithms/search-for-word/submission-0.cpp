class Solution {
public:
    int m, n;
    vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};

    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& visited,
             int i, int j, int ind, string& word) {
        if (ind == (int)word.length()) return true;
        if (i < 0 || j < 0 || i >= m || j >= n) return false;
        if (visited[i][j]) return false;
        if (board[i][j] != word[ind]) return false;

        visited[i][j] = true;

        for (auto& dir : directions) {
            if (dfs(board, visited, i+dir[0], j+dir[1], ind+1, word))
                return true;
        }

        visited[i][j] = false;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (dfs(board, visited, i, j, 0, word))
                    return true;

        return false;
    }
};